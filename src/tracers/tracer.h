#ifndef __TRACER__
#define __TRACER__

// base class for describing tracers for objects

#include "constants.h"
#include "ray.h"
#include "rgbcolour.h"

class World; // only pointers - forward class reference ok

class Tracer
{
public:
    Tracer();
    Tracer(World *w_ptr);
    ~Tracer();

    virtual RGBColour trace_ray(const Ray &ray) const; // trace ray

    // todo - with depth

protected:
    World *world_ptr;
};

#endif
