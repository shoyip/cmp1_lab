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

		double theta() {
			double theta;
			double magnitude = this->magnitude();
			cout << "mag: " << magnitude << endl;
			cout << "x: " << x_ << endl;
			cout << "ratio: " << magnitude / x_ << endl;
			theta = acos(x_ / magnitude);
			return theta;
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

// Main function

int main() {

	// Debug print

	Vector3D v;
	v.print();

	Vector3D v1(1,2,3);
	v1.print();

	// Debug getter methods
	
	cout << v1.getX() << ", " << v1.getY() << ", " << v1.getZ() << endl;

	// Debug setter methods
	
	v1.setX(7);
	v1.print();

	// Debug scalar product
	
	Vector3D v2(4,5,6);
	v2.print();
	double sp = v1.scalarProduct(v2);
	cout << "Scalar Product between v1 and v2 is " << sp << endl;

	// Debug scalar product
	
	Vector3D vp = v1.vectorProduct(v2);
	cout << "Vector Product between v1 and v2 is " << endl;
	vp.print();

	// Debug magnitude
	
	cout << v1.magnitude() << "\n" << v2.magnitude() << endl;

	// Debug theta
	.955317
	cout << v1.theta() << "\n" << v2.theta() << endl;

	Vector3D v3(1,1,1);
	cout << v3.theta() << endl;

	return 0;
}
