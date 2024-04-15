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
			: radius(radius_),
			center(pos)
		{
			bodyColor = bodyColor_;
			mass = mass_;
			velocity = vel;
			sigma = sigma_;
			flag = 0;
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			bbox = AABB(point3D(pos.x - radius_, pos.y - radius_, 0.0f), 
				point3D(pos.x + radius_, pos.y + radius_, 1.0f));
		}

		void updatePosition(float time) const override;

		void addVelocity(velocity2D velocity, point2D poc) const override;

		void addForce(force2D force, point2D poc) const override;

		float radius;
		point2D center;
	};
}
