#pragma once

#include "Core/Vector.h"
#include "Core/Body.h"

namespace Minator
{
	class Triangle : public Body
	{
	public:

		Triangle(Color bodyColor_ = MAROON,
			float mass_ = 0.0f,
			velocity2D vel = velocity2D(),
			float sigma_ = 0.0f,
			point2D a_ = point2D(),
			point2D b_ = point2D(),
			point2D c_ = point2D())
			: a(a_), b(b_), c(c_)
		{
			bodyColor = bodyColor_;
			mass = mass_;
			velocity = vel;
			sigma = sigma_;
			flag = 0;
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			a += c;
		}

		void updatePosition(float time) const override;

		void addVelocity(velocity2D velocity, point2D poc) const override;

		void addForce(force2D force, point2D poc) const override;

		point2D a, b, c;
	};
}

