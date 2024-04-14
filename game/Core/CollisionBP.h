#pragma once

#include <memory>
#include <vector>

#include "Core/Body.h"
#include "Core/Scene.h"

namespace Minator
{
	struct BPCU
	{
		std::vector<std::shared_ptr<Body>> bodyList;
	};

	// Implementing Sweep and prune
	// TODO : BVH implementation
	class BroadPhaseCollision
	{
	public:

		BroadPhaseCollision()
		{

		}


		std::shared_ptr<Scene> sceneBuffer;
	};



}
