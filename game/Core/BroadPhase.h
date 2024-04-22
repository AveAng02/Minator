#pragma once

#include <memory>
#include <vector>

#include "Core/Body.h"
#include "Core/Scene.h"

namespace Minator
{
	struct BPCU
	{
		std::shared_ptr<Body> body1;
		std::shared_ptr<Body> body2;
	};

	// Implementing Sweep and prune
	// TODO : BVH implementation
	class BroadPhase
	{
	public:

		BroadPhase()
		{

		}

		// function to chunk out BPCUs

		std::shared_ptr<Scene> sceneBuffer;
	};



}
