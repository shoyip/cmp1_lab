// Vector.cpp
// A program that enables the user to define and make computations with vectors
// in three dimensions.

#include <iostream>
#include <cmath>

using namespace std;

// Definition of the Vector3D class

class Vector3D {
	public:
		// Constructors
		// ============

		Vector3D() {}
		
		Vector3D(double x, double y, double z) {
			// This is the constructor of the Vector3D object.
			// A Vector3D object is defined by three parameters,
			// which correspond to the three cartesian coordinates
			// x, y and z.
			//
			// Parameters
			// ==========
			// 	x: double
			// 		Real number for the first cartesian
			// 		component of the vector
			// 	y: double
			// 		Real number for the second cartesian
			// 		component of the vector
			// 	z: double
			// 		Real number for the third cartesian
			// 		component of the vector
			x_ = x;
			y_ = y;
			z_ = z;
		}
		//ciao
		Vector3D(const Vector3D& vector) {
			// This method is a copy constructor, and it allows the
			// user to assign an existing instance of Vector3D to a
			// newly defined one.
			//
			// Parameters
			// ==========
			// 	vector: Vector3D
			// 		Previously defined Vector3D instance
			x_ = vector.x_;
			y_ = vector.y_;
			z_ = vector.z_;
		}

		// Getter Methods
		// ==============

		// These getter methods allow the user to get the real values
		// of the single cartesian components x, y or z.
		//
		// Returns
		// =======
		// 	{x, y, z}: double
		// 		Value of the {x, y, z} component

		const double getX() { return x_; }
		const double getY() { return y_; }
		const double getZ() { return z_; }

		// Setter Methods
		// ==============

		// These setter methods allow the user to set the real values
		// of the single cartesian components x, y or z.
		//
		// Parameters
		// ==========
		// 	{x, y, z}: double
		// 		Value of the {x, y, z} component to be newly set

		void setX(double x) { x_ = x; }
		void setY(double y) { y_ = y; }
		void setZ(double z) { z_ = z; }

		// Other Methods
		// =============

		double scalarProduct(const Vector3D& vector2) {
			// This method computes the scalar product between the
			// instantiated vector and a second vector that is passed
			// as an argument, returning a real number.
			//
			// Parameters
			// ==========
			// 	vector2: Vector3D
			// 		The second vector to apply the scalar
			// 		product to
			//
			// Returns
			// =======
			// 	result: double
			// 		The result of the scalar product
			double result;
			result = x_ * vector2.x_ + y_ * vector2.y_ + z_ * vector2.z_;
			return result;
		}

		Vector3D vectorProduct(const Vector3D& vector2) {
			// This method computes the vector product between the
			// instantiated vector and the vector passed as an
			// argument.
			//
			// Parameters
			// ==========
			// 	vector2: Vector3D
			// 		Vector to be passed in the product on the
			// 		RHS of the cross product
			//
			// Returns
			// =======
			// 	resultVector: Vector3D
			// 		Vector resulting from the cross product
			double rvx = y_ * vector2.z_ - z_ * vector2.y_;
			double rvy = z_ * vector2.x_ - x_ * vector2.z_;
			double rvz = x_ * vector2.y_ - y_ * vector2.x_;

			return Vector3D(rvx, rvy, rvz);
		}

		double magnitude() {
			// Compute magnitude of the instantiated vector
			//
			// Returns
			// =======
			// 	result: double
			// 		Value of magnitude of instantiated vector

			double result;
			result = sqrt(x_*x_ + y_*y_ + z_*z_);
			return result;
		}
		//inclination theta=[0,pi]
		double theta() {
			double theta;
			double magnitude = this->magnitude();
			cout << "mag: " << magnitude << endl;
			cout << "x: " << x_ << endl;
			cout << "ratio: " << magnitude / x_ << endl;
			theta = acos(z_ / magnitude);
			return theta;
		}
		//azimuth phi=[0,2pi]
		double phi() {
			double phi;
			double magnitude = this->magnitude();
			if (x_ > 0) {

				phi = atan(y_ / x_);
			}
			else if (x_ < 0 && y_ >= 0) {
				phi = atan(y_ / x_) + M_PI;
			
			}
			else if (x_ < 0 && y_ < 0) {
				phi = atan(y_ / x_) - M_PI;

			}
			else if (x_ = 0 && y_ > 0) {
				phi = M_PI/2;

			}

			else if (x_ = 0 && y_ < 0) {
				phi = -M_PI / 2;

			}
			else {
				cout << "The angle phi is undefined" << endl;
			}
			return phi;
		}

		// Debug Methods
		// =============

		void print() {
			// This method is useful for debug, and it allows the
			// user to print out the cartesian coordinates of a
			// Vector3D instance.
			cout << "The vector you defined is:\n"
				<< "x: " << x_ << "\n"
				<< "y: " << y_ << "\n"
				<< "z: " << z_ << endl;
		}

	private:
		double x_;
		double y_;
		double z_;
};