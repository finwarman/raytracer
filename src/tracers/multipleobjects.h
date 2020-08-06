#ifndef __MULTIPLEOBJECTS__
#define __MULTIPLEOBJECTS__

#include "tracer.h"

class MultipleObjects : public Tracer
{
public:
    MultipleObjects();
    MultipleObjects(World *w_ptr);

    virtual ~MultipleObjects();

    virtual RGBColour trace_ray(const Ray &ray) const;
};

#endif
