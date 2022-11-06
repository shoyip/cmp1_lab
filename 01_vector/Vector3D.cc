#include <iostream>
#include <cmath>

#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D() {}

Vector3D::Vector3D(double x, double y, double z)
{
    x_ = x;
    y_ = y;
    z_ = z;
}

Vector3D::Vector3D(const Vector3D &vector)
{
    x_ = vector.x_;
    y_ = vector.y_;
    z_ = vector.z_;
}

const double Vector3D::getX() { return x_; }
const double Vector3D::getY() { return y_; }
const double Vector3D::getZ() { return z_; }

void Vector3D::setX(double x) { x_ = x; }
void Vector3D::setY(double y) { y_ = y; }
void Vector3D::setZ(double z) { z_ = z; }

const double Vector3D::scalarProduct(const Vector3D &vector2)
{
    double result;
    result = x_ * vector2.x_ + y_ * vector2.y_ + z_ * vector2.z_;
    return result;
}

Vector3D Vector3D::vectorProduct(const Vector3D &vector2)
{
    double rvx = y_ * vector2.z_ - z_ * vector2.y_;
    double rvy = z_ * vector2.x_ - x_ * vector2.z_;
    double rvz = x_ * vector2.y_ - y_ * vector2.x_;

    return Vector3D(rvx, rvy, rvz);
}

double const Vector3D::magnitude()
{
    double result;
    result = sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    return result;
}

double const Vector3D::theta()
{
    double theta;
    theta = acos(z_ / this->magnitude());
    return theta;
}

double const Vector3D::phi()
{
    double phi;
    if (x_ > 0)
    {
        // the point is in the first or fourth xy quadrant
        phi = atan(y_ / x_);
    }
    else if (x_ < 0)
    {
        // the point is in the second or third xy quadrant
        phi = atan(y_ / x_) + M_PI;
    }
    else if (x_ == 0 && y_ > 0)
    {
        // the point is on the upper singularity of atan
        phi = M_PI / 2.;
    }
    else if (x_ == 0 && y_ < 0)
    {
        // the point is on the lower singularity of atan
        phi = -M_PI / 2.;
    }
    return phi;
}

double const Vector3D::angle(Vector3D &vector2)
{
    double angle;
    angle = acos(this->scalarProduct(vector2) / (this->magnitude() * vector2.magnitude()));
    return angle;
}

Vector3D Vector3D::operator+(const Vector3D &vector2) const
{
    double new_x, new_y, new_z;
    new_x = x_ + vector2.x_;
    new_y = y_ + vector2.y_;
    new_z = z_ + vector2.z_;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

Vector3D Vector3D::operator-(const Vector3D &vector2) const
{
    double new_x, new_y, new_z;
    new_x = x_ - vector2.x_;
    new_y = y_ - vector2.y_;
    new_z = z_ - vector2.z_;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

Vector3D Vector3D::operator=(const Vector3D &vector2)
{
    x_ = vector2.x_;
    y_ = vector2.y_;
    z_ = vector2.z_;
    return *this;
}

Vector3D Vector3D::operator*(const double factor)
{
    double new_x, new_y, new_z;
    new_x = factor * x_;
    new_y = factor * y_;
    new_z = factor * z_;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

Vector3D Vector3D::operator/(const double factor)
{
    double new_x, new_y, new_z;
    new_x = x_ / factor;
    new_y = y_ / factor;
    new_z = z_ / factor;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

void Vector3D::print()
{
    cout << "The vector you defined is:\n"
         << "x: " << x_ << "\n"
         << "y: " << y_ << "\n"
         << "z: " << z_ << endl;
}