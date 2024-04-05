#pragma once

#include <vector>

#include "raylib.h"

namespace Minator
{
	class AABB
	{
	public:
		
		AABB(Vector3 min_ = Vector3(),
			Vector3 max_ = Vector3())
			: min(min_),
			  max(max_)
		{
			box.min = min_;
			box.max = max_;
		}

		Vector3 min; // TODO : Replace with custom vector class
		Vector3 max;

		BoundingBox box;

		// checks if the sent bounding box overlaps with this
		bool overlaps(AABB sentBox);

		void drawBox();

	private:


	};
}

