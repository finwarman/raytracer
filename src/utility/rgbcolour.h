#ifndef __RGBCOLOUR__
#define __RGBCOLOUR__

class RGBColour
{
public:
    float r, g, b;

    RGBColour();                             // default constructor
    RGBColour(float c);                      // constructor (c - grey)
    RGBColour(float _r, float _g, float _b); // constructor (r, g, b)
    RGBColour(const RGBColour &c);           // copy constructor

    ~RGBColour(); // destructor

    // assignment
    RGBColour &operator=(const RGBColour &rhs); // assignment operator

    // operators
    RGBColour operator+(const RGBColour &c) const; // addition
    RGBColour &operator+=(const RGBColour &c);     // compound addition

    RGBColour operator*(const float a) const;      // multiplication by a float on the right
    RGBColour &operator*=(const float a);          // compound multiplication by a float on the right
    RGBColour operator*(const RGBColour &c) const; // component-wise multiplication

    RGBColour operator/(const float a) const; // division by a float
    RGBColour &operator/=(const float a);     // compound division by a float

    bool operator==(const RGBColour &c) const; // comparison - are two RGBColours the same?

    RGBColour powc(float p) const; // raise components to a power
    float average(void) const;     // the average of the components
};

// inlined member functions

// operator+ - addition of two Colours
inline RGBColour RGBColour::operator+(const RGBColour &c) const
{
    return (RGBColour(r + c.r, g + c.g, b + c.b));
}

// operator+= - compound addition of two Colours
inline RGBColour &RGBColour::operator+=(const RGBColour &c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

// operator* - multiplication by a float on the right
inline RGBColour RGBColour::operator*(const float a) const
{
    return (RGBColour(r * a, g * a, b * a));
}

// operator*= - compound multiplication by a float on the right
inline RGBColour &RGBColour::operator*=(const float a)
{
    r *= a;
    g *= a;
    b *= a;
    return (*this);
}

// operator/ - division by float
inline RGBColour RGBColour::operator/(const float a) const
{
    return (RGBColour(r / a, g / a, b / a));
}

// operator/= -  compound division by float
inline RGBColour &RGBColour::operator/=(const float a)
{
    r /= a;
    g /= a;
    b /= a;
    return (*this);
}

// operator* - component-wise multiplication of two Colours
inline RGBColour RGBColour::operator*(const RGBColour &c) const
{
    return (RGBColour(r * c.r, g * c.g, b * c.b));
}

// operator== - are two RGBColours the same?
inline bool RGBColour::operator==(const RGBColour &c) const
{
    return (r == c.r && g == c.g && b == c.b);
}

// average - the average of the three components
inline float RGBColour::average(void) const
{
    return (0.333333333333 * (r + g + b));
}

// inlined non-member function

// operator* - multiplication by a float on the left
RGBColour operator*(const float a, const RGBColour &c);
inline RGBColour operator*(const float a, const RGBColour &c)
{
    return (RGBColour(a * c.r, a * c.g, a * c.b));
}

#endif
