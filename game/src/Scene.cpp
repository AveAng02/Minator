
#include "raylib.h"

#include "include/Scene.h"

namespace Minator
{
	void Scene::updateScene(float time)
	{
		for (auto &body : bodyList)
			body.updatePosition(time);
	}

	void Scene::addBody(const Body& body)
	{
		bodyList.push_back(body);
	}

	void Scene::drawScene()
	{
		ClearBackground(RAYWHITE);

		// drawing all objects defined as body
		for (auto i : bodyList)
			i.drawBody();
	}

	bool Scene::detectCollisions()
	{
		// Detect collision with walls
		for (auto& body : bodyList)
		{
			if ((body.x + body.radius + 1) > wallX || (body.x - body.radius - 1) < 0.0f)
				body.vx *= -1;

			if ((body.y + body.radius + 1) > wallY || (body.y - body.radius - 1) < 0.0f)
				body.vy *= -1;
		}

		// Detect collision between bodies 
		// for now consider all the bodies as spheres

		return false;
	}
}

