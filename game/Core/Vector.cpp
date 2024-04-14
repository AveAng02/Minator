
#include "Vector.h"

namespace Minator
{
	float vector2D::dot(const vector2D vec) const
	{
		return (x * vec.x) + (y + vec.y);
	}

	float vector3D::dot(const vector3D vec) const 
	{
		return (x * vec.x) + (y + vec.y) + (z * vec.z);
	}

	vector3D vector3D::cross(const vector3D vec) const
	{
		return vector3D((y * vec.z - z * vec.y), (z * vec.x - x * vec.z), (x * vec.z - y * vec.x));
	}
}


