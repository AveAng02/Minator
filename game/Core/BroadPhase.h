#pragma once

#include <memory>
#include <vector>
#include <queue>

#include "Core/Body.h"
#include "Core/Scene.h"

namespace Minator
{
	struct BPCU
	{
		std::shared_ptr<Body> body1;
		std::shared_ptr<Body> body2;

		BPCU()
			: body1(nullptr), 
			  body2(nullptr) {}

		BPCU(std::shared_ptr<Body> a,
			std::shared_ptr<Body> b)
			: body1(a), body2(b)
		{}
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

		int sortAndSweep(std::queue<BPCU>& queue) const;

		std::shared_ptr<Scene> sceneBuffer;

	private:

		bool runFlag;
	};



}
