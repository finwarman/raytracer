#include "multipleobjects.h"
#include "world.h"
#include "shaderec.h"

// default constructor
MultipleObjects::MultipleObjects() : Tracer() {} // call parent constructor

// constructor
MultipleObjects::MultipleObjects(World *w_ptr) : Tracer(w_ptr) {}

// destructor
MultipleObjects::~MultipleObjects(){};

// trace_ray (ray is tested for intersection against the single sphere in this world)
RGBColour MultipleObjects::trace_ray(const Ray &ray) const
{
    ShadeRec sr(world_ptr->hit_objects(ray));
    double t; // not used

    if (sr.hit_an_object)
    {
        return sr.colour;
    }
    else
    {
        return world_ptr->background_colour;
    }
}
