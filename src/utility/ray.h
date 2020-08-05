#ifndef __RAY__
#define __RAY__

#include "point3d.h"
#include "vector3d.h"

class Ray
{
public:
    Point3D o;  // origin
    Vector3D d; // direction

    Ray(); // default constructor

    Ray(const Point3D &origin, const Vector3D &dir); // constructor

    Ray(const Ray &ray); // copy constructor

    Ray &operator=(const Ray &rhs); // assignment operator overload

    ~Ray(); // destructor
};

#endif
