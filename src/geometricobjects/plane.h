#ifndef __PLANE__
#define __PLANE__

// plane class - simplest geometric object (inherits from GeometricObject)

#include "geometricobject.h"

class Plane : public GeometricObject
{
public:
    Plane(void);
    Plane(const Point3D p, const Normal &n);

    // TODO ...

    virtual bool hit(const Ray &ray, double &t, ShadeRec &s) const;

private:
    Point3D point;                // point through which the plane passes
    Normal normal;                // normal to the plane
    static const double kEpsilon; // TODO - see chapter 16
};

bool Plane::hit(const Ray &ray, double &tmin, ShadeRec &sr) const // did ray hit object?, modify tmin for nearest hit point (if any), and return shading info
{
    double t = (point - ray.o) * normal / (ray.d * normal); // if d*n=0, t = INF

    if (t > kEpsilon) // TODO - explain (chap 16 - this finds closest point?)
    {
        tmin = t;
        sr.normal = normal;
        sr.local_hit_point = ray.o + t * ray.d;

        return true;
    }
    else
    {
        return false;
    }
}

#endif
