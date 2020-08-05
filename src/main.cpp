#include "world/world.h"

// main method to run the raytracer
int main()
{
    World w;          // construct default world object
    w.build();        // uses build function included in world/world.cpp
    w.render_scene(); // render the scene!

    return 0;
}
