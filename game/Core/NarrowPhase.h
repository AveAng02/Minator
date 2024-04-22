#pragma once

#include <memory>
#include <vector>

#include "Core/Body.h"
#include "Core/BroadPhase.h"

namespace Minator
{
	typedef BPCU NPCU;

	// Only 1 instance of this object per thread for the lifecycle of the program
	// Implementing Sweep and prune
	// TODO : BVH implementation
	class NarrowPhase
	{
	public:

		NarrowPhase()
		{

		}

		// functions to chunk out NPCUs

		std::shared_ptr<BPCU> sceneBuffer;
	};

}
