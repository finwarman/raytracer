#include "world.h"

#include <iostream> // todo - remove?

// main method to run the raytracer
int main()
{
    World w;          // construct default world object
    w.build();        // uses build function included in world/world.cpp
    w.render_scene(); // render the scene!

    std::cout << "\nRunning raytracer... done!\n";

    return 0;
}
