
#include <iostream>

#include "raylib.h"

#include "Core/AABB.h"


namespace Minator
{
	bool AABB::overlaps(AABB sentBox)
	{
		bool retValX = (box.min.x > sentBox.box.min.x && box.min.x < sentBox.box.max.x)
						|| (box.max.x > sentBox.box.min.x && box.max.x < sentBox.box.max.x);

		bool retValY = (box.min.y > sentBox.box.min.y && box.min.y < sentBox.box.max.y)
						|| (box.max.y > sentBox.box.min.y && box.max.y < sentBox.box.max.y);

		if (retValX && retValY)
			std::cout << "Overlaps" << std::endl;

		return retValX && retValY;
	}

	void AABB::drawBox()
	{
		DrawBoundingBox(box, RED);
	}
}

