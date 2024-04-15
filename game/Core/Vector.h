#pragma once


namespace Minator
{
	class vector2D
	{
	public:

		vector2D(float x_ = 0.0f,
				 float y_ = 0.0f)
			: x(x_), y(y_)
		{}


		float dot(const vector2D vec) const;
		float mag() const;
		float magSquared() const;
		vector2D normalize() const;

		vector2D& operator=(vector2D vec)
		{
			x = vec.x;
			y = vec.y;
		}

		vector2D& operator+(const vector2D& vec)
		{
			return vector2D(x + vec.x, y + vec.y);
		}

		vector2D& operator-(const vector2D& vec)
		{
			return vector2D(x - vec.x, y - vec.y);
		}

		vector2D& operator+=(const vector2D& vec)
		{
			x += vec.x; 
			y += vec.y;
			return *this;
		}

		vector2D& operator-=(const vector2D& vec)
		{
			x -= vec.x;
			y -= vec.y;
			return *this;
		}

		vector2D& operator*(float value)
		{
			return vector2D(x * value, y * value);
		}

		vector2D& operator/(float value)
		{
			return vector2D(x / value, y / value);
		}

		vector2D& operator*=(float value)
		{
			x *= value;
			y *= value;
		}

		vector2D& operator/=(float value)
		{
			x /= value;
			y /= value;
		}

		float x, y;

	private:

	};

	typedef vector2D point2D;
	typedef vector2D direction2D;
	typedef vector2D velocity2D;
	typedef vector2D force2D;
	typedef vector2D impulse2D;

	class vector3D
	{
	public:

		vector3D(float x_ = 0.0f,
			float y_ = 0.0f,
			float z_ = 0.0f)
			: x(x_), y(y_), z(z_)
		{}

		vector3D(point2D point)
			: x(point.x), y(point.y), z(0.0f)
		{}


		float dot(const vector3D vec) const;
		vector3D cross(const vector3D vec) const;
		float mag() const;
		float magSquared() const;
		vector3D normalize() const;

		vector3D& operator=(const vector3D& vec)
		{
			x = vec.x;
			y = vec.y;
			z = vec.z;
			return *this;
		}

		vector3D& operator+=(const vector3D& vec)
		{
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		vector3D& operator-=(const vector3D& vec)
		{
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
		}

		vector3D& operator*(float value)
		{
			return vector3D(x * value, y * value, z * value);
		}

		vector3D& operator/(float value)
		{
			return vector3D(x / value, y / value, z / value);
		}

		vector3D& operator*=(float value)
		{
			x *= value;
			y *= value;
			z *= value;
		}

		vector3D& operator/=(float value)
		{
			x /= value;
			y /= value;
			z /= value;
		}



		float x, y, z;

	private:

	};

	typedef vector3D point3D;
	typedef vector3D velocity3D;
}
