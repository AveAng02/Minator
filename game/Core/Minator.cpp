
#include "Minator.h"

namespace Minator
{
	int Minator::addBody(const std::shared_ptr<Body> bodyPtr)
	{
		return scene->addBody(bodyPtr);
	}
}

