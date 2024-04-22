#pragma once

#include <vector>
#include <memory>

#include "Body.h"

namespace Minator
{
	class Scene
	{
	public:

		Scene()
		{

		}


		int addBody(const std::shared_ptr<Body> bodyPtr);

		// void drawScene() const;

		std::vector<std::shared_ptr<Body>> bodyList; // IMP: convert to pointer of vector of bodies



	};
}
