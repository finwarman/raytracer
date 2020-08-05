#include "shaderec.h"
#include "constants.h"

// constructor (initialise defaults)
ShadeRec::ShadeRec(World &wr)
    : hit_an_object(false),
      local_hit_point(),
      normal(),
      colour(black),
      t(0.0),
      w(wr)
{
}

// copy constructor
ShadeRec::ShadeRec(const ShadeRec &sr)
    : hit_an_object(sr.hit_an_object),
      local_hit_point(sr.local_hit_point),
      normal(sr.normal),
      colour(sr.colour),
      t(sr.t),
      w(sr.w)
{
}
