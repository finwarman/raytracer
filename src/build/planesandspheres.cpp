// builds a scene consisting of several spheres and a plane

void World::build()
{

    vp.set_hres(60);
    vp.set_vres(30);

    vp.set_pixel_size(1.0);
    vp.set_gamma(1.0);

    background_colour = black;              // set world background colour
    tracer_ptr = new MultipleObjects(this); // create tracer of 'MultipleObjects' type

    // add objects

    // spheres
    Sphere *sphere_ptr = new Sphere();

    sphere_ptr->set_centre(0.0);
    sphere_ptr->set_radius(13.0);
    sphere_ptr->set_colour(red); // red
    add_object(sphere_ptr);

    sphere_ptr = new Sphere(Point3D(-10, -5, -10), 8);
    sphere_ptr->set_colour(RGBColour(1, 0.5, 0)); // yellow
    add_object(sphere_ptr);

    // planes
    Plane *plane_ptr = new Plane(Point3D(0, 0, -20), Normal(20, 0.2, 1));
    plane_ptr->set_colour(RGBColour(0.0, 0.3, 0.0)); // dark green
    add_object(plane_ptr);
}
