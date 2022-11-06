// Definition of the Vector3D class

class Vector3D
{
public:
    // Constructors
    // ============

    Vector3D();

    Vector3D(double x, double y, double z);
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

    Vector3D(const Vector3D &vector);
    // This method is a copy constructor, and it allows the
    // user to assign an existing instance of Vector3D to a
    // newly defined one.
    //
    // Parameters
    // ==========
    // 	vector: Vector3D
    // 		Previously defined Vector3D instance

    // Getter Methods
    // ==============

    // These getter methods allow the user to get the real values
    // of the single cartesian components x, y or z.
    //
    // Returns
    // =======
    // 	{x, y, z}: double
    // 		Value of the {x, y, z} component

    const double getX();
    const double getY();
    const double getZ();

    // Setter Methods
    // ==============

    // These setter methods allow the user to set the real values
    // of the single cartesian components x, y or z.
    //
    // Parameters
    // ==========
    // 	{x, y, z}: double
    // 		Value of the {x, y, z} component to be newly set

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    // Other Methods
    // =============

    const double scalarProduct(const Vector3D &vector2);
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

    Vector3D vectorProduct(const Vector3D &vector2);
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

    double const magnitude();
    // Compute magnitude of the instantiated vector
    //
    // Returns
    // =======
    // 	result: double
    // 		Value of magnitude of instantiated vector

    double const theta();
    // Compute the inclination angle theta, which spans [0, pi]
    //
    // Returns
    // =======
    //  theta: double
    //      Value of the theta angle

    double const phi();
    // Compute the azimuthal angle phi, which spans [0, 2*pi]
    //
    // Returns
    // =======
    //  phi: double
    //      Value of the phi angle

    double const angle(Vector3D &vector2);
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

    // Overload operators
    // ==================

    Vector3D operator+(const Vector3D &vector2) const;
    // Overload addition operator
    //
    // Parameters
    // ==========
    //  vector2: Vector3D
    //      vector on the rhs of the operator
    //
    // Returns
    // =======
    //  new_vector: Vector3D
    //      result of the operation

    Vector3D operator-(const Vector3D &vector2) const;
    // Overload subtraction operator
    //
    // Parameters
    // ==========
    //  vector2: Vector3D
    //      vector on the rhs of the operator
    //
    // Returns
    // =======
    //  new_vector: Vector3D
    //      result of the operation

    Vector3D operator=(const Vector3D &vector2);
    // Overload copy operator (what to do with const?)
    //
    // Parameters
    // ==========
    //  vector2: Vector3D
    //      vector on the rhs of the operator
    //
    // Returns
    // =======
    //  new_vector: Vector3D
    //      result of the operation

    Vector3D operator*(const double factor);
    // Overload multiplication by float operator (how to multiply from left?)
    //
    // Parameters
    // ==========
    //  factor: double
    //      factor of multiplication
    //
    // Returns
    // =======
    //  new_vector: Vector3D
    //      result of the operation

    Vector3D operator/(const double factor);
    // Overload division by float operator
    //
    // Parameters
    // ==========
    //  factor: double
    //      factor of division
    //
    // Returns
    // =======
    //  new_vector: Vector3D
    //      result of the operation

    // Debug Methods
    // =============

    void print();
    // This method is useful for debug, and it allows the
    // user to print out the cartesian coordinates of a
    // Vector3D instance.

private:
    double x_;
    double y_;
    double z_;
};
