
#include "raylib.h"

#include "Core/Scene.h"

namespace Minator
{
	void Scene::updateScene(float time)
	{
		// Use prior fram info to update

		for (auto &body : bodyList)
			body->updatePosition(time);
	}

	void Scene::addBody(const std::shared_ptr<Body> bodyPtr)
	{
		bodyList.push_back(bodyPtr);
	}

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
					body->vx *= -1;
				else if (body->flag == -2)
					body->vy *= -1;
				else if (body->flag == -3)
				{
					// loading variables
					// float m1 = bodyList[body->collideID]->mass;
					float ux1 = bodyList[body->collideID]->vx;
					float uy1 = bodyList[body->collideID]->vy;

					// float m2 = body->mass;
					float ux2 = body->vx;
					float uy2 = body->vy;

					// calculating ratios
					// float r1 = (m1 - m2) / (m1 + m2);
					// float r2 = 2 * m1 / (m1 - m2);
					// float r3 = 2 * m2 / (m1 + m2);

					// calculating final values
					bodyList[body->collideID]->vx = ux2;
					body->vx = ux1;

					bodyList[body->collideID]->vy = uy2;
					body->vy = uy1;

					bodyList[body->collideID]->hasCollided = false;
					bodyList[body->collideID]->flag = 0;
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
				dist1 = bodyList[i]->radius + bodyList[j]->radius;
				dist1 = (dist1 * dist1) + 3.0f;
				dx = (bodyList[i]->x - bodyList[j]->x) * (bodyList[i]->x - bodyList[j]->x);
				dy = (bodyList[i]->y - bodyList[j]->y) * (bodyList[i]->y - bodyList[j]->y);
				dist2 = dx + dy;

				if (dist2 < dist1)
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
}

