#ifndef __PLANE__
#define __PLANE__

// sphere class - inherits from GeometricObject

#include "geometricobject.h"

class Sphere : public GeometricObject
{
public:
    Sphere(void); // Default constructor

    Sphere(Point3D centre, double r); // constructor

    Sphere(const Sphere &sphere); // copy constructor

    virtual Sphere *clone(void) const; // virtual copy constructor

    virtual ~Sphere(void); // destructor

    Sphere &operator=(const Sphere &sphere); // assignment operator

    // setters

    void set_centre(const Point3D &c);

    void set_centre(const double x, const double y, const double z);

    void set_radius(const double r);

    // determine if ray hit sphere (and where)
    virtual bool hit(const Ray &ray, double &t, ShadeRec &s) const;

private:
    Point3D centre;               // centre of the sphere
    double radius;                // radius of the sphere
    static const double kEpsilon; // TODO - see chapter 16
};

inline void Sphere::set_centre(const Point3D &c)
{
    centre = c;
}

inline void Sphere::set_centre(const double x, const double y, const double z)
{
    centre.x = x;
    centre.y = y;
    centre.z = z;
}

inline void Sphere::set_radius(const double r)
{
    radius = r;
}

#endif
