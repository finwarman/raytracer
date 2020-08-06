#ifndef __WORLD__
#define __WORLD__

#include "viewplane.h"
#include "rgbcolour.h"
#include "sphere.h"
#include "tracer.h"

#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
// using namespace std;

//class RenderThread;

class World
{
public:
    ViewPlane vp;
    RGBColour background_colour;
    Sphere sphere; // chapter 3 only
    Tracer *tracer_ptr;
    std::vector<GeometricObject *> objects;

    // store brightness chars
    const static std::string brightness_chars[];

    World();  // default constructor
    ~World(); // destructor

    void build();
    void render_scene() const;

    // todo - add object

    // colour clamping
    RGBColour max_to_one(const RGBColour &c) const;
    RGBColour clamp_to_colour(const RGBColour &c) const;

    void open_windows(const int hres, const int vres) const; // horizontal and vertical resolution

    // draw pixel of given colour at position
    void display_pixel(const int row, const int column, const RGBColour &pixel_colour) const;

    ShadeRec hit_objects(const Ray &ray);

private:
    void
    delete_objects(void);
};

// todo - object adding etc.

#endif
