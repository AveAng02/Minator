#pragma once

#include "Core/Vector.h"
#include "Core/Body.h"

namespace Minator
{
	class Circle : public Body
	{
	public:

		Circle(Color bodyColor_ = MAROON,
			float mass_ = 0.0f,
			velocity2D vel = velocity2D(),
			float sigma_ = 0.0f,
			point2D pos = point2D(),
			float radius_ = 0.0f)
			: radius(radius_)
		{
			bodyColor = bodyColor_;
			center = pos;
			mass = mass_;
			velocity = vel;
			sigma = sigma_;
			flag = 0;
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			bbox = AABB(point3D(0.0f, 0.0f, 0.0f), point3D(1.0f, 1.0f, 0.0f));
		}

		float radius;
		point2D center;
	};
}
