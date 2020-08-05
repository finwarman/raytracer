// this file contains the definition of the class GeometricObject

#include "utility/constants.h"
#include "utility/rgbcolour.h" // todo - material
#include "geometricobjects/geometricobject.h"

// default constructor
GeometricObject::GeometricObject(void) : colour(black) {}

// copy constructor
GeometricObject::GeometricObject(const GeometricObject &object)
{
    colour = object.colour; // todo - pointer / null
}

// assignment operator
GeometricObject &GeometricObject::operator=(const GeometricObject &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    colour = rhs.colour;
    return *this;
}

// destructor
GeometricObject::~GeometricObject() {}
// todo - if using pointer, delete object and set NULL

// todo - set colour?
// todo - set material
