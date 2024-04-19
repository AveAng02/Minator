#pragma once

#include <queue>

#include "Core/Scene.h"
#include "Core/CollisionBP.h"
#include "Core/CollisionNP.h"
#include "Core/CollisionR.h"

namespace Minator
{
	class Minator
	{
	public:

		Minator()
		{

		}




		std::shared_ptr<Scene> sceneBuffer;

		std::shared_ptr<CollisionBP> broadPhaseCollider;
		std::queue<BPCU> breadPhaseQueue;

		std::shared_ptr<CollisionNP> narrowPhaseCollider;
		std::queue<NPCU> narrowPhaseQueue;

		std::shared_ptr<CollisionR> collisionResolver;

	private:

	};
}


