
#include "Body/Square.h"

namespace Minator
{
	void Square::updatePosition(float time)
	{

	}

	void Square::addVelocity(velocity2D velocity, point2D poc)
	{
		// TODO : account for point of contact and angular momentum
		this->velocity += velocity;
	}

	void Square::addForce(force2D force, point2D poc)
	{
		// TODO : account for point of contact and angular momentum
		this->force += force;
	}
}


