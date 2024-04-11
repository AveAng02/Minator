#pragma once

#include <memory>

#include "Body.h"

namespace Minator
{
	class QuadTree
	{
	public:

		QuadTree()
			:	topLeft(nullptr),
				topRight(nullptr),
				bottomLeft(nullptr),
				bottomRight(nullptr)
		{

		}

		// Inserting new node
		int insert(Body body);

		// building the tree for the first time
		int buildTree();

		// Balancing the tree after the peices have moved
		int rebalanceTree();

		std::shared_ptr<QuadTree> topLeft;
		std::shared_ptr<QuadTree> topRight;
		std::shared_ptr<QuadTree> bottomLeft;
		std::shared_ptr<QuadTree> bottomRight;

	private:

	};
}