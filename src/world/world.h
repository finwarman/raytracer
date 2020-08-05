#ifndef __WORLD__
#define __WORLD__

#include "world/viewplane.h"
#include "utility/rgbcolour.h"
#include "geometricobjects/sphere.h"
#include "tracers/tracer.h"

#include <vector>
#include <algorithm>
// using namespace std;

//class RenderThread;

class World
{
public:
    ViewPlane vp;
    RGBColour background_colour;
    Sphere sphere; // chapter 3 only
    Tracer *tracer_ptr;
    std::vector<GeometricObject *> objects;

    World();  // default constructor
    ~World(); // destructor

    void build();
    void render_scene() const;

    // todo - add object

    // colour clamping
    RGBColour max_to_one(const RGBColour &c) const;
    RGBColour clamp_to_colour(const RGBColour &c) const;

    void open_windows(const int hres, const int vres) const; // horizontal and vertical resolution

    // draw pixel of given colour at position
    void display_pixel(const int row, const int column, const RGBColour &pixel_colour) const;

    ShadeRec hit_objects(const Ray &ray);

private:
    void
    delete_objects(void);
};

// todo - object adding etc.

#endif