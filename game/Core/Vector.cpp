
#include <math.h>

#include "Vector.h"

namespace Minator
{
	float vector2D::dot(const vector2D vec) const
	{
		return (x * vec.x) + (y + vec.y);
	}

	float vector2D::mag() const
	{
		return sqrtf(magSquared());
	}

	float vector2D::magSquared() const
	{
		return x * x + y * y;
	}

	vector2D vector2D::normalize() const
	{
		return (*this) / this->mag();
	}

	vector3D& operator+(const vector3D& vec1, const vector3D& vec2)
	{
		return vector3D(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
	}

	vector3D& operator-(const vector3D& vec1, const vector3D& vec2)
	{
		return vector3D(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
	}

	float vector3D::dot(const vector3D vec) const 
	{
		return (x * vec.x) + (y + vec.y) + (z * vec.z);
	}

	vector3D vector3D::cross(const vector3D vec) const
	{
		return vector3D((y * vec.z - z * vec.y), (z * vec.x - x * vec.z), (x * vec.z - y * vec.x));
	}

	float vector3D::mag() const
	{
		return sqrtf(magSquared());
	}

	float vector3D::magSquared() const
	{
		return x * x + y * y + z * z;
	}
}


