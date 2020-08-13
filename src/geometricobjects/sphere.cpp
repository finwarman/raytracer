#include "sphere.h"
#include <math.h>

const double Sphere::kEpsilon = 0.001;

// default constructor
Sphere::Sphere() : GeometricObject(), centre(0.0), radius(1.0) {}

//constructor
Sphere::Sphere(Point3D c, double r) : GeometricObject(), centre(c), radius(r) {}

// clone
Sphere *Sphere::clone(void) const { return (new Sphere(*this)); }

// copy constructor
Sphere::Sphere(const Sphere &sphere) : GeometricObject(sphere), centre(sphere.centre), radius(sphere.radius) {}

// assignment
Sphere &Sphere::operator=(const Sphere &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    GeometricObject::operator=(rhs);

    centre = rhs.centre;
    radius = rhs.radius;

    return *this;
}

// destructor
Sphere::~Sphere() {}

// hit
// bool: did ray hit this sphere?, modify tmin for nearest hit point (if any), and modify shading info
bool Sphere::hit(const Ray &ray, double &tmin, ShadeRec &sr) const
{
    // TODO - explain this formula (and use useful variable names)
    double t;
    Vector3D temp = ray.o - centre;
    double a = ray.d * ray.d;
    double b = 2.0 * temp * ray.d;
    double c = temp * temp - radius * radius;
    double disc = b * b - 4.0 * a * c;

    if (disc < 0.0)
    {
        return false;
    }
    else
    {
        double e = sqrt(disc); // todo import sqrt
        double denom = 2.0 * a;
        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon)
        {
            tmin = t;
            sr.normal = (temp + t * ray.d) / radius;
            sr.local_hit_point = ray.o + t * ray.d;

            return true;
        }

        t = (-b - e) / denom; // larger root

        if (t > kEpsilon)
        {
            tmin = t;
            sr.normal = (temp + t * ray.d) / radius;
            sr.local_hit_point = ray.o + t * ray.d;

            return true;
        }
        // todo - reduce above duplicate code
    }
    return false;
}
