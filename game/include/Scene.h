#pragma once

#include <vector>

#include "Body.h"

namespace Minator
{
	class Scene
	{
	public:

		// TODO : Define a seperate and better class for time
		void updateScene(float time);

		void addBody(const Body& body);

		void drawScene();

		bool detectCollisions();

		std::vector<Body> bodyList;

		// TODO: This part needs a better design
		float wallX;
		float wallY;
	};
}
