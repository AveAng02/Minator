
#include "Body/Triangle.h"

namespace Minator
{
	void Triangle::updatePosition(float time) 
	{

	}

	void Triangle::addVelocity(velocity2D velocity, point2D poc) 
	{
		// TODO : account for point of contact and angular momentum
		this->velocity += velocity;
	}

	void Triangle::addForce(force2D force, point2D poc) 
	{
		// TODO : account for point of contact and angular momentum
		this->force += force;
	}
}