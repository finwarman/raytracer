// definition of class for world

#include "world/world.h"

// constants - used for kEpsilon and kHugeValue
#include "utility/constants.h"

// geometric objects
#include "geometricobjects/sphere.h"
// #include "geometricobjects/plane.h"

// utils
#include "utility/vector3d.h"
#include "utility/point3d.h"
#include "utility/normal.h"
#include "utility/ray.h"
#include "utility/shaderec.h"

// tracers
#include "tracers/singlesphere.h"

// build functions
#include "build/build.cpp" // builds the red sphere! - todo rename

// world member function definitions:

// default constructor
World::World(void) : background_colour(black), tracer_ptr(NULL) {}

// destructor
World::~World()
{
    if (tracer_ptr)
    {
        delete tracer_ptr;
        tracer_ptr = NULL;
    }

    delete_objects();
}

// render scene - orthographic view along zw axis

void World::render_scene() const
{
    RGBColour pixel_colour;
    Ray ray;
    int hres = vp.hres;
    int vres = vp.vres;
    float s = vp.s;
    float zw = 100.0; // hardcoded

    ray.d = Vector3D(0, 0, -1); // direction of ray along z axis

    // up, then across -
    // trace a ray orthoganally from each pixel on the view plane, and display resulting pixel colour
    for (int r = 0; r < vres; r++)
    {
        for (int c = 0; c <= hres; c++)
        {
            ray.o = Point3D(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw);
            pixel_colour = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_colour);
        }
    }
}

// clamp - limit colour values to 1
RGBColour World::max_to_one(const RGBColour &c) const
{
    float max_val = std::max(c.r, std::max(c.g, c.b));

    if (max_val > 1.0)
    {
        return (c / max_val);
    }
    return (c);
}

// clamp_to_colour - Set Colour to red if any component is greater than one
RGBColour World::clamp_to_colour(const RGBColour &raw_colour) const
{
    RGBColour c(raw_colour);

    if (raw_colour.r > 1.0 || raw_colour.g > 1.0 || raw_colour.b > 1.0)
    {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }

    return (c);
}

// ---------------------------------------------------------------------------display_pixel
// raw_colour is the pixel Colour computed by the ray tracer
// its RGB floating point components can be arbitrarily large
// mapped_colour has all components in the range [0, 1], but still floating point
// display colour has integer components for computer display
// the Mac's components are in the range [0, 65535]
// a PC's components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_colour
// the function SetCPixel is a Mac OS function

void World::display_pixel(const int row, const int column, const RGBColour &raw_colour) const
{
    RGBColour mapped_colour;

    if (vp.show_out_of_gamut)
    {
        mapped_colour = clamp_to_colour(raw_colour);
    }
    else
    {
        mapped_colour = max_to_one(raw_colour);
    }

    if (vp.gamma != 1.0)
    {
        mapped_colour = mapped_colour.powc(vp.inv_gamma);
    }

    //have to start from max y coordinate to convert to screen coordinates
    int x = column;
    int y = vp.vres - row - 1;

    // todo
    // paintArea->setPixel(x, y, (int)(mapped_Colour.r * 255),
    //                     (int)(mapped_Colour.g * 255),
    //                     (int)(mapped_Colour.b * 255));
}

// ----------------------------------------------------------------------------- hit_objects

ShadeRec
World::hit_objects(const Ray &ray)
{

    ShadeRec sr(*this);
    double t;
    Normal normal;
    Point3D local_hit_point;
    float tmin = kHugeValue;
    int num_objects = objects.size();

    for (int j = 0; j < num_objects; j++)
        if (objects[j]->hit(ray, t, sr) && (t < tmin))
        {
            sr.hit_an_object = true;
            tmin = t;
            sr.colour = objects[j]->get_colour(); // todo - pointer?
            //sr.hit_point = ray.o + t * ray.d;
            normal = sr.normal;
            local_hit_point = sr.local_hit_point;
        }

    if (sr.hit_an_object)
    {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }

    return sr;
}

//------------------------------------------------------------------ delete_objects

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty

void World::delete_objects(void)
{
    int num_objects = objects.size();

    for (int j = 0; j < num_objects; j++)
    {
        delete objects[j];
        objects[j] = NULL;
    }

    objects.erase(objects.begin(), objects.end());
}