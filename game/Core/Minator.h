#pragma once

#include <queue>

#include "Core/Scene.h"
#include "Core/BroadPhase.h"
#include "Core/NarrowPhase.h"
#include "Core/CollisionResolver.h"

namespace Minator
{
	class Minator
	{
	public:

		Minator()
		{
			scene = std::make_shared<Scene>();
		}


		int addBody(const std::shared_ptr<Body> bodyPtr) const;

		int runTests();


		std::shared_ptr<Scene> scene;

		std::shared_ptr<BroadPhase> broadPhaseCollider;
		std::queue<BPCU> broadPhaseQueue;

		std::shared_ptr<NarrowPhase> narrowPhaseCollider;
		std::queue<NPCU> narrowPhaseQueue;

		std::shared_ptr<CollisionResolver> collisionResolver;

	private:

	};
}


