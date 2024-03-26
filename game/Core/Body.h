#pragma once

#include <vector>
#include <string>

#include "raylib.h"

namespace Minator
{
	// TODO: Make a virtual class and define a rigid body and soft body
	class Body
	{
	public:
		Body(Color bodyColor_ = MAROON,
			float x_ = 0.0f,
			float y_ = 0.0f,
			float mass_ = 0.0f,
			float radius_ = 0.0f,
			float vx_ = 0.0f,
			float vy_ = 0.0f,
			float sigma_ = 0.0f)
			: bodyColor(bodyColor_),
			x(x_),
			y(y_),
			mass(mass_),
			radius(radius_),
			vx(vx_),
			vy(vy_),
			sigma(sigma_),
			flag(0),
			hasCollided(false),
			hasInfiniteMass(false),
			hasGravity(false)
		{}

						// Define a seperate class named time
		void updatePosition(float time);

		void addForce(float xComponent, float yComponent, const std::string& lable);

		void addImpulse(float xComponent, float yComponent, const std::string& lable);

		void drawBody();

		// force list
		// TODO : Replace with force class
		std::vector<float> forceX;
		std::vector<float> forceY;
		std::vector<std::string> forceLable;

		// impulse list
		// TODO : Replace with impulse class
		std::vector<float> impulseX;
		std::vector<float> impulseY;
		std::vector<std::string> impulseLable;

		// TODO : define a class named velocity
		// Defined in meters per second
		// converted to pixels per frame
		std::string bodyName;
		Color bodyColor;

		float vx;
		float vy;


		float x;
		float y;
		float radius; // TODO: for now consider all bodies as sphere. Needs to be virtualized
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

		int collideID; // TODO: better design needed
	};
}
