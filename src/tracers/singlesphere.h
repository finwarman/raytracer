#ifndef __SINGLESPHERE__
#define __SINGLESPHERE__

#include "tracer.h"

class SingleSphere : public Tracer
{
public:
    SingleSphere();
    SingleSphere(World *w_ptr);

    virtual ~SingleSphere();

    virtual RGBColour trace_ray(const Ray &ray) const;
};

#endif
