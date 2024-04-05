
#include "raylib.h"

#include "Core/Body.h"

namespace Minator
{
	void Body::updatePosition(float time)
	{
		float dx = vx * time, dy = vy * time;

		x += dx;
		y += dy;

		// TODO : Decouple this part later
		box.box.min.x += dx;
		box.box.min.y += dy;

		box.box.max.x += dx;
		box.box.max.y += dy;
	}

	void Body::addForce(float xComponent, float yComponent, const std::string& lable)
	{

	}

	void Body::addImpulse(float xComponent, float yComponent, const std::string& lable)
	{

	}
	
	void Body::drawBody()
	{
		// for now consider all bodies as sphere
		// TODO: Write a wrapper class for raylib
		DrawCircle(x, y, radius, bodyColor);
		box.drawBox(); // TODO : Remove later
	}
}
