
#include "Minator.h"

namespace Minator
{
	int Minator::addBody(const std::shared_ptr<Body> bodyPtr) const
	{
		return scene->addBody(bodyPtr);
	}

	int Minator::runTests()
	{
		BPCU unit;

		broadPhaseCollider->sceneBuffer = scene;
		broadPhaseCollider->sortAndSweep(broadPhaseQueue);

		while (!broadPhaseQueue.empty())
		{
			unit = broadPhaseQueue.front();

			if (narrowPhaseCollider->satAlgorithm(unit))
				narrowPhaseQueue.push(unit);
		}

		return 1;
	}
}

