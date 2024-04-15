#pragma once

#include "Core/Vector.h"
#include "Core/Body.h"

namespace Minator
{
	class Square : public Body
	{
	public:

		Square(Color bodyColor_ = MAROON,
			float mass_ = 0.0f,
			velocity2D vel = velocity2D(),
			float sigma_ = 0.0f,
			point2D tL = point2D(),
			point2D bR = point2D())
			: topLeft(tL),
			bottomRight(bR)
		{
			bodyColor = bodyColor_;
			mass = mass_;
			velocity = vel;
			sigma = sigma_;
			flag = 0;
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			bbox = AABB(point3D(bR), point3D(tL));
		}

		void updatePosition(float time) const override;

		void addVelocity(velocity2D velocity, point2D poc) const override;

		void addForce(force2D force, point2D poc) const override;

		point2D topLeft;
		point2D bottomRight;
	};
}

