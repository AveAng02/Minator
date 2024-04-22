
#include "raylib.h"

#include "Core/Scene.h"

namespace Minator
{
	int Scene::addBody(const std::shared_ptr<Body> bodyPtr)
	{
		bodyList.push_back(bodyPtr);

		return 0;
	}

	/*
	void Scene::drawScene() const
	{
		ClearBackground(RAYWHITE);

		// drawing all objects defined as body
		for (const auto& i : bodyList)
			i->drawBody();
	}

	void Scene::updateCollisions()
	{
		// TODO : Create a event system that abstracts away this collision detection and response
		// Update according to walls
		for (const auto& body : bodyList)
		{
			if (body->hasCollided)
			{
				if (body->flag == -1)
					body->bodyVel.x *= -1;
				else if (body->flag == -2)
					body->bodyVel.y *= -1;
				else if (body->flag == -3)
				{
					
				}
			}

			body->hasCollided = false;
			body->flag = 0;
		}


		// Clear and reset states

	}

	bool Scene::detectCollisions() const
	{
		bool hasCollided = false;

		// Detect collision with walls
		for (const auto& body : bodyList)
		{
			if ((body->x + body->radius + 1) > wallX || (body->x - body->radius - 1) < 0.0f)
			{
				hasCollided = true;
				body->hasCollided = true;
				body->flag = -1;
			}
			
			if ((body->y + body->radius + 1) > wallY || (body->y - body->radius - 1) < 0.0f)
			{
				hasCollided = true;
				body->hasCollided = true;
				body->flag = -2;
			}
		}

		// Detect collision between bodies 
		// for now consider all the bodies as spheres
		int len = bodyList.size();
		float dist1 = 0.0f, dist2 = 0.0f;
		float dx = 0.0f, dy = 0.0f;

		for (int j = 0, i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				// dist1 = bodyList[i]->radius + bodyList[j]->radius;
				// dist1 = (dist1 * dist1) + 3.0f;
				// dx = (bodyList[i]->x - bodyList[j]->x) * (bodyList[i]->x - bodyList[j]->x);
				// dy = (bodyList[i]->y - bodyList[j]->y) * (bodyList[i]->y - bodyList[j]->y);
				// dist2 = dx + dy;

				if (bodyList[i]->box.overlaps(bodyList[j]->box))
				{
					hasCollided = true;

					bodyList[i]->hasCollided = true;
					bodyList[i]->flag = -3;
					bodyList[i]->collideID = j;

					bodyList[j]->hasCollided = true;
					bodyList[j]->flag = -3;
					bodyList[j]->collideID = i;
				}
			}
		}

		return hasCollided;
	}
	*/
}

