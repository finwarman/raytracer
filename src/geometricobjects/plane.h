#ifndef __PLANE__
#define __PLANE__

// plane class - simplest geometric object (inherits from GeometricObject)

#include "geometricobject.h"

class Plane : public GeometricObject
{
public:
    Plane(void);
    Plane(const Point3D &p, const Normal &n);
    Plane(const Plane &plane); // copy constructor

    virtual Plane *clone() const;

    Plane &operator=(const Plane &rhs);

    virtual ~Plane();

    void set_colour(const RGBColour &_colour);

    virtual bool hit(const Ray &ray, double &t, ShadeRec &s) const;

private:
    Point3D point;                // point through which the plane passes
    Normal normal;                // normal to the plane
    static const double kEpsilon; // TODO - see chapter 16
};

inline void Plane::set_colour(const RGBColour &_colour)
{
    colour = _colour;
}

#endif
