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

		const double scalarProduct(const Vector3D& vector2) {
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

		double const magnitude() {
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
        
        double const theta() {
            // Compute the inclination angle theta, which spans [0, pi]
            //
            // Returns
            // =======
            //  theta: double
            //      Value of the theta angle
            double theta;
            theta = acos(z_ / this->magnitude());
            return theta;
        }

        double const phi() {
            // Compute the azimuthal angle phi, which spans [0, 2*pi]
            //
            // Returns
            // =======
            //  phi: double
            //      Value of the phi angle
            double phi;
            if (x_ > 0) {
                // the point is in the first or fourth xy quadrant
                phi = atan(y_ / x_);
            } else if (x_ < 0) {
                // the point is in the second or third xy quadrant
                phi = atan(y_ / x_) + M_PI;
            } else if (x_ == 0 && y_ > 0) {
                // the point is on the upper singularity of atan
                phi = M_PI / 2.;
            } else if (x_ == 0 && y_ < 0) {
                // the point is on the lower singularity of atan
                phi = -M_PI / 2.;
            }
            return phi;
        }

        double const angle(Vector3D& vector2) {
            // Compute the angle between the current vector and another one.
            // Spans [0, pi].
            //
            // Parameters
            // ==========
            //  vector2: Vector3D
            //      The vector with which the angle is to be computed
            //
            // Returns
            // =======
            //  angle: double
            //      The angle between the two vectors in radians
            double angle;
            angle = acos(this->scalarProduct(vector2) / (this->magnitude() * vector2.magnitude()));
            return angle;
        }
       
        // Overload operators
        // ==================
        
        Vector3D operator+(const Vector3D& vector2) const {
            double new_x, new_y, new_z;
            new_x = x_ + vector2.x_;
            new_y = y_ + vector2.y_;
            new_z = z_ + vector2.z_;
            Vector3D new_vector(new_x, new_y, new_z);
            return new_vector;
        }
        
        Vector3D operator-(const Vector3D& vector2) const {
            double new_x, new_y, new_z;
            new_x = x_ - vector2.x_;
            new_y = y_ - vector2.y_;
            new_z = z_ - vector2.z_;
            Vector3D new_vector(new_x, new_y, new_z);
            return new_vector;
        }
        
        Vector3D operator=(const Vector3D& vector2) {
            x_ = vector2.x_;
            y_ = vector2.y_;
            z_ = vector2.z_;
            return *this;
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

int main () {
    Vector3D v1;

    cout << "Vector v2" << endl;
    Vector3D v2(1,2,3);

    cout << v2.theta() << endl;
    cout << v2.phi() << endl;

    cout << "Vector v3" << endl;
    Vector3D v3(-10,5,7);

    cout << v3.theta() << endl;
    cout << v3.phi() << endl;

    cout << "Angle between v2 and v3" << endl;
    cout << v3.angle(v2) << endl;

    Vector3D v4;
    v4 = v2 + v3;
    v4.print();

    Vector3D v5;
    v5 = v4;
    v5.print();
}
