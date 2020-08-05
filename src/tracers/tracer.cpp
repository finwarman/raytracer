#include "tracer.h"

// default constructor
Tracer::Tracer() : world_ptr(NULL) {}

// constructor (world pointer)
Tracer::Tracer(World *w_ptr) : world_ptr(w_ptr) {}

// destructor
Tracer::~Tracer()
{
    if (world_ptr)
    {
        world_ptr = NULL;
    }
}

// trace_ray (default - always black)
RGBColour Tracer::trace_ray(const Ray &ray) const
{
    return black;
}

// todo - trace_ray (depth)
