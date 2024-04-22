#pragma once

#include "Core/Vector.h"
#include "Core/Body.h"

namespace Minator
{
	class Circle : public Body
	{
	public:

		Circle(color4D bodyColor_ = color4D(190, 33, 55, 255),
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
			hasCollided = false;
			hasGravity = false;
			hasInfiniteMass = false;

			bbox = AABB(point3D(pos.x - radius_, pos.y - radius_, 0.0f), 
				point3D(pos.x + radius_, pos.y + radius_, 1.0f));
		}

		virtual void updatePosition(float time) override;

		virtual void addVelocity(velocity2D velocity, point2D poc) override;

		virtual void addForce(force2D force, point2D poc) override;

		virtual point2D furthestSupportPoint(const direction2D d) const override;

		float radius;
		point2D center;
	};
}
