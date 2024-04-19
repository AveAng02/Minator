#pragma once

#include <memory>
#include <vector>

#include "Core/Body.h"
#include "Core/CollisionBP.h"

namespace Minator
{
	struct NPCU
	{
		std::shared_ptr<Body> body1;
		std::shared_ptr<Body> body2;
	};

	// Only 1 instance of this object per thread for the lifecycle of the program
	// Implementing Sweep and prune
	// TODO : BVH implementation
	class CollisionNP
	{
	public:

		CollisionNP()
		{

		}

		// functions to chunk out NPCUs

		std::shared_ptr<BPCU> sceneBuffer;
	};

}
