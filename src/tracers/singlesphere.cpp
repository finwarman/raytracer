
#include "tracers/singlesphere.h"
#include "world/world.h"
#include "utility/shaderec.h"

// default constructor
SingleSphere::SingleSphere() : Tracer() {} // call parent constructor

// constructor
SingleSphere::SingleSphere(World *w_ptr) : Tracer(w_ptr) {}

// destructor
SingleSphere::~SingleSphere(){};

// trace_ray (ray is tested for intersection against the single sphere in this world)
RGBColour SingleSphere::trace_ray(const Ray &ray) const
{
    ShadeRec sr(*world_ptr); // not used
    double t;                // not used

    if (world_ptr->sphere.hit(ray, t, sr))
    {
        // red if collision, else black
        return (red);
    }
    else
    {
        return (black);
    }
}
