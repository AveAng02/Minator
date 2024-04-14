#pragma once

#include <vector>

#include "raylib.h"

#include "Vector.h"

namespace Minator
{
	class AABB
	{
	public:
		
		AABB(vector3D min_ = vector3D(),
			vector3D max_ = vector3D())
			: min(min_),
			  max(max_)
		{}

		vector3D min; // TODO : Replace with custom vector class
		vector3D max;

		// checks if the sent bounding box overlaps with this
		bool overlaps(AABB sentBox);

		void drawBox();

	private:


	};
}

