#ifndef __SHADEREC__
#define __SHADEREC__

// utility class to store all information required to SHADE a ray-object hit point.
// (i.e. computing the the colour that's reflected back along the ray)

#include <vector>

// can use forward references when dealing with pointers (as opposed to direct objects)
class RGBColour; // todo - material
class World;

// We need the following as #includes instead of forward class declarations,
// because we have the objects themselves, not pointers or references

#include "utility/point3d.h"
#include "utility/normal.h"
#include "utility/ray.h"
#include "utility/rgbcolour.h"

class ShadeRec
{
public:
    bool hit_an_object;      // did the ray collide with an object?
    Point3D local_hit_point; // world coords of hit point
    Normal normal;           // normal at hit point
    RGBColour colour;        // colour for shading N.B. ONLY chapter 3
    float t;                 // ray parameter
    World &w;                // world reference, for shading (used to prevent default constructor)

    ShadeRec(World &wr);          // constructor
    ShadeRec(const ShadeRec &sr); // copy constructor
};

#endif
