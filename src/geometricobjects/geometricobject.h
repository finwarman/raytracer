#ifndef __GEOMETRICOBJECT__
#define __GEOMETRICOBJECT__

// base class for all geometric objects
// children e.g.: spheres, planes

class RGBColour; // todo - material

#include "point3d.h"
#include "ray.h"
#include "shaderec.h"

class GeometricObject
{
public:
    GeometricObject();                              // default constructor
    GeometricObject(const GeometricObject &object); // copy constructor

    virtual GeometricObject *clone() const = 0; // virtual copy constructor
    virtual ~GeometricObject();                 // destructor

    RGBColour get_colour() const; // get colour of object (chapter 3 only - todo, pointer?)

    virtual bool hit(const Ray &ray, double &tmin, ShadeRec &sr) const = 0;

protected:
    RGBColour colour; // colour of object N.B. only used in chapter 3 (becomes material)

    GeometricObject &operator=(const GeometricObject &rhs); // assignment operator
};

inline RGBColour GeometricObject::get_colour() const // todo - pointer?
{
    return colour;
}

#endif
