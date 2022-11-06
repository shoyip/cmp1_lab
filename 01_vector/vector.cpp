// Vector.cpp
// A program that enables the user to define and make computations with vectors
// in three dimensions.

#include <iostream>
#include <cmath>

#include "Vector3D.h"

using namespace std;

int main () {
    cout << "Hello! This program implements a Vector3D class for vectors in three dimensional space." << endl;
    cout << "It is able to handle both cartesian and spherical coordinates." << endl;

    cout << "Now a vector will be defined with the default values." << endl;
    Vector3D v1;

    cout << "Now another vector will be defined using cartesian coordinates, namely x=1, y=2, z=3." << endl;
    Vector3D v2(1,2,3);
    v2.print();

    cout << "Values for theta and phi." << endl;
    cout << v2.theta() << endl;
    cout << v2.phi() << endl;

    cout << "Now a second vector will be defined using cartesian coordinates, x=-10, y=5, z=7." << endl;
    Vector3D v3(-10,5,7);
    v3.print();

    cout << "Values for theta and phi." << endl;
    cout << v3.theta() << endl;
    cout << v3.phi() << endl;

    cout << "Angle between v2 and v3" << endl;
    cout << v3.angle(v2) << endl;

    cout << "Now overload operators are tested" << endl;
    Vector3D v4;
    v4 = v2 + v3;
    v4.print();

    Vector3D v5;
    v5 = v4;
    v5.print();

    Vector3D v6;
    v6 = v3 / 2.;
    v6.print();

    Vector3D v7;
    v7 = v3 * 1.3;
    v7.print();
}
