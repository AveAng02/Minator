
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

	point2D Square::furthestSupportPoint(const direction2D d) const
	{
		float aVal = a.dot(d),
			bVal = b.dot(d),
			cVal = c.dot(d),
			dVal = d.dot(d);

		return (aVal > bVal) ? (aVal > cVal) ? (aVal > dVal) ? a : d :
			(cVal > dVal) ? c : d : (bVal > cVal) ? (bVal > dVal) ?
			b : d : (cVal > dVal) ? c : d;
	}
}



