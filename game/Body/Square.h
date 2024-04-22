#pragma once

#include "Core/Vector.h"
#include "Core/Body.h"

namespace Minator
{
	class Square : public Body
	{
	public:

		Square(color4D bodyColor_ = color4D(190, 33, 55, 255),
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
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			bbox = AABB(point3D(bR), point3D(tL));
		}

		virtual void updatePosition(float time) override;

		virtual void addVelocity(velocity2D velocity, point2D poc) override;

		virtual void addForce(force2D force, point2D poc) override;

		point2D topLeft;
		point2D bottomRight;
	};
}

