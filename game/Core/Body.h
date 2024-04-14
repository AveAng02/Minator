#pragma once

#include <vector>
#include <string>

#include "raylib.h"

#include "Core/AABB.h"
#include "Core/Vector.h"

namespace Minator
{
	// TODO: Make a virtual class and define a rigid body and soft body
	class Body
	{
	public:

		Body(Color bodyColor_ = MAROON,
			float mass_ = 0.0f,
			velocity2D vel = velocity2D(),
			float sigma_ = 0.0f)
			: bodyColor(bodyColor_),
			mass(mass_),
			velocity(vel),
			sigma(sigma_),
			flag(0),
			hasCollided(false),
			hasInfiniteMass(false),
			hasGravity(false)
		{
			bbox = AABB(point3D(0.0f, 0.0f, 0.0f), point3D(1.0f, 1.0f, 0.0f));
		}

						// Define a seperate class named time
		virtual void updatePosition(float time) = 0;

		virtual void addForce(force2D force, point2D poc) = 0;

		virtual void addImpulse(impulse2D impulse, point2D poc) = 0;

		virtual void drawBody() = 0;


		// TODO : define a class named velocity
		// Defined in meters per second
		// converted to pixels per frame
		std::string bodyName;

		Color bodyColor;

		velocity2D velocity;
		
		float mass;
		float sigma; // coefficient of restitution

		mutable bool hasCollided;
		bool hasGravity;
		bool hasInfiniteMass;

		/*
		* -1 for change in x axis
		* -2 for change in y axis
		* -3 collision with another ball
		*/
		int flag; 

		AABB bbox;
	};
}
