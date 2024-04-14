#pragma once

#include <vector>
#include <memory>

#include "Body.h"

namespace Minator
{
	class Scene
	{
	public:

		Scene(float wallX_ = 0.0f,
			float wallY_ = 0.0f)
			:	wallX(wallX_),
				wallY(wallY_)
		{}

		// TODO : Define a seperate and better class for time
		void updateScene(float time);

		void addBody(const std::shared_ptr<Body> bodyPtr);

		void drawScene() const;

		std::vector<std::shared_ptr<Body>> bodyList; // IMP: convert to pointer of vector of bodies

		// TODO: This part needs a better design
		float wallX;
		float wallY;

	};
}
