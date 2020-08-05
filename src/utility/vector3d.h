#ifndef __VECTOR3D__
#define __VECTOR3D__

// todo #include "matrix.h"

// forward class declarations
class Normal;
class Point3D;

class Vector3D
{
public:
    double x, y, z;

public:
    Vector3D();                                // default constructor
    Vector3D(double a);                        // constructor (a)
    Vector3D(double _x, double _y, double _z); // constructor (x, y, z)
    Vector3D(const Vector3D &v);               // copy constructor
    Vector3D(const Normal &n);                 // constructs a vector from a Normal
    Vector3D(const Point3D &p);                // constructs a vector from a point

    ~Vector3D(); // destructor

    // getters
    double length();      // length
    double len_squared(); // square of the length

    // assignment
    Vector3D &operator=(const Vector3D &rhs); // assignment operator
    Vector3D &operator=(const Normal &rhs);   // assign a Normal to a vector
    Vector3D &operator=(const Point3D &rhs);  // assign a Point3D to a vector

    // operators (double)
    Vector3D operator*(const double a) const; // multiplication by a double on the right
    Vector3D operator/(const double a) const; // division by a double

    // operators (vector)
    Vector3D operator+(const Vector3D &v) const; // addition
    Vector3D &operator+=(const Vector3D &v);     // compound addition
    Vector3D operator-(const Vector3D &v) const; // subtraction
    Vector3D operator^(const Vector3D &v) const; // cross product
    double operator*(const Vector3D &b) const;   // dot product

    // operators (unary)
    Vector3D operator-() const; // unary minus
    Vector3D &hat();            // return a unit vector, and normalize the vector
    void normalize();           // convert vector to a unit vector
};

// inlined member functions

// unary minus -
// this does not change the current vector
// this allows ShadeRec objects to be declared as constant arguments in many shading
// functions that reverse the direction of a ray that's stored in the ShadeRec object
inline Vector3D Vector3D::operator-() const
{
    return (Vector3D(-x, -y, -z));
}

// len_squared - the square of the length
inline double Vector3D::len_squared()
{
    return (x * x + y * y + z * z);
}

// operator* - multiplication by a double on the right
inline Vector3D Vector3D::operator*(const double a) const
{
    return (Vector3D(x * a, y * a, z * a));
}

// operator/ - division by a double
inline Vector3D Vector3D::operator/(const double a) const
{
    return (Vector3D(x / a, y / a, z / a));
}

// operator+ - addition
inline Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return (Vector3D(x + v.x, y + v.y, z + v.z));
}

// operator- - subtraction
inline Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return (Vector3D(x - v.x, y - v.y, z - v.z));
}

// operator* - dot product
inline double Vector3D::operator*(const Vector3D &v) const
{
    return (x * v.x + y * v.y + z * v.z);
}

// operator^ - cross product
inline Vector3D Vector3D::operator^(const Vector3D &v) const
{
    return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

// operator+= - compound addition
inline Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

// inlined non-member function

// operator* - multiplication by a double on the left

Vector3D operator*(const double a, const Vector3D &v);
inline Vector3D operator*(const double a, const Vector3D &v)
{
    return (Vector3D(a * v.x, a * v.y, a * v.z));
}

// TODO
// non-inlined non-member function

// operator*
// multiplication by a matrix on the left

// Vector3D
// operator*(const Matrix &mat, const Vector3D &v);

#endif
