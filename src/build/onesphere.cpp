// Builds a scene consisting of 1 red sphere"

void World::build()
{
    vp.set_hres(60);
    vp.set_vres(30);

    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    background_colour = black;           // set world background colour
    tracer_ptr = new SingleSphere(this); // create tracer of 'SingleSphere' type

    // intialise single sphere in world
    sphere.set_centre(0.0);
    sphere.set_radius(13.0);
}
