#pragma once

#include <vector>
#include <string>

namespace Minator
{
	class Body
	{
	public:
		Body()
		:   vx(0.0f),
			vy(0.0f),
			x(0.0f),
			y(0.0f),
			mass(0.0f),
			radius(100.0f),
			hasGravity(true),
			hasInfiniteMass(false)
		{}

						// Define a seperate class named time
		void updatePosition(float time);

		void addForce(float xComponent, float yComponent, std::string lable);

		void addImpulse(float xComponent, float yComponent, std::string lable);

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
		float vx;
		float vy;


		float x;
		float y;
		float radius; // TODO: for now consider all bodies as sphere. Needs to be virtualized
		float mass;

		bool hasGravity;
		bool hasInfiniteMass;
	};
}
