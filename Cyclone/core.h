namespace cyclone {

	/**
	* Holds a vector in 3 dimensions. Four data members are allocated
	* to ensure alignment in an array.
	*/

	class Vector3
	{
	public:
		/** Holds the value along the x axis. */
		real x;

		/** Holds the value along the y axis. */
		real y;

		/** Holds the value along the z axis. */
		real z;

	private:
		/** Padding to ensure 4-word alignment. */
		real pad;

	public:
		/** The default constructor creates a zero vector. */
		Vector3() : x(0), y(0), z(0) {}

		/** * The explicit constructor creates a vector with the given * components. */
		Vector3(const real x, const real y, const real z)
			: x(x), y(y), z(z) {}

		void invert()
		{
			(*this).x = -x;
			(*this).y = -y;
			(*this).z = -z;
		}

		/** Gets the magnitude of this vector. */
		real findMagnitude() const
		{
			return real_sqrt(x*x + y*y + z*z);
		}

		/** Gets the squared magnitude of this vector. */
		real findSquareMagnitude() const
		{
			return x*x + y*y + z*z;
		}

		/** Turns a non-zero vector into a vector of unit length. */
		void normalize()
		{
			real magnitude = findMagnitude();
			if (magnitude > 0)
			{
				(*this) *= (((real)1) / magnitude);
			}
		}

		/** Multiplies this vector by the given scalar. */
		void operator*=(const real value)
		{
			x *= value; y *= value; z *= value;
		}

		/** Returns a copy of this vector scaled to the given value. */
		Vector3 operator*(const real value) const
		{
			return Vector3(x*value, y*value, z*value);
		}

		/** Adds the given vector to this. */
		void operator+=(const Vector3& vector)
		{
			x += vector.x; y += vector.y; z += vector.z;
		}
		/** * Returns the value of the given vector added to this. */
		Vector3 operator+(const Vector3& vector) const
		{
			return Vector3(x + vector.x, y + vector.y, z + vector.z);
		}
	};
}