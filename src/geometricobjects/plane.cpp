#include "plane.h"

const double Plane::kEpsilon = 0.001; // todo explain

// default constructor
Plane::Plane()
    : GeometricObject(),
      point(0.0),
      normal(0, 1, 0)
{
}

// constructor
Plane::Plane(const Point3D &_point, const Normal &_normal)
    : GeometricObject(),
      point(_point),
      normal(_normal)
{
    normal.normalize();
}

// copy construcotr

Plane::Plane(const Plane &plane)
    : GeometricObject(plane),
      point(plane.point),
      normal(plane.normal)
{
}

// clone

Plane *Plane::clone(void) const
{
    return (new Plane(*this));
}

// assignment
Plane &Plane::operator=(const Plane &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    GeometricObject::operator=(rhs);

    point = rhs.point;
    normal = rhs.normal;

    return *this;
}

// destructor
Plane::~Plane() {}

// hit

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
