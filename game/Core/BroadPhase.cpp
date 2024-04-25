
#include <vector>

#include "Body.h"
#include "BroadPhase.h"

namespace Minator
{
	int BroadPhase::sortAndSweep(std::queue<BPCU>& queue) const
	{
		std::vector<std::shared_ptr<Body>> bodies = sceneBuffer->bodyList;

		// Comparision along x axis
		struct xComparator
		{
			bool operator() (std::shared_ptr<Body> a, std::shared_ptr<Body> b)
			{
				return a->bbox.min.x < b->bbox.min.x;
			}
		} myComparator;

		std::sort(bodies.begin(), bodies.end(), myComparator);

		for (int i = 0; i < bodies.size() - 1; i++)
		{
			float xMin = bodies[i]->bbox.min.x;
			float xMax = bodies[i]->bbox.max.x;

			for (int j = i + 1; j < bodies.size(); j++)
			{
				// Checking if the bounding boxes collide
				if (xMin < bodies[j]->bbox.min.x < xMax
					|| xMin < bodies[j]->bbox.max.x < xMax)
				{
					queue.push(BPCU(bodies[i], bodies[j]));
				}
				else
				{
					break;
				}
			}
		}

		return 1;
	}

}
