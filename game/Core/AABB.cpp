
#include <iostream>

#include "Core/AABB.h"


namespace Minator
{
	bool AABB::overlaps(AABB sentBox)
	{
		bool retValX = (min.x > sentBox.min.x && min.x < sentBox.max.x)
						|| (max.x > sentBox.min.x && max.x < sentBox.max.x);

		bool retValY = (min.y > sentBox.min.y && min.y < sentBox.max.y)
						|| (max.y > sentBox.min.y && max.y < sentBox.max.y);

		if (retValX && retValY)
			std::cout << "Overlaps" << std::endl;

		return retValX && retValY;
	}
}

