#pragma once

#include <memory>

#include "AABB.h"
#include "Body.h"

namespace Minator
{
	/*
	* 
	* References:
	* [1] https://jimkang.com/quadtreevis/
	* [2] https://github.com/wedusk101/C/blob/master/quadtree.c#L39
	* [3] Computational Geometry: Algorithms and Applications Book 
		  by Marc van Kreveld, Mark Overmars, and Mark de Berg
	* 
	*/
	class QuadTree
	{
	public:

		enum QuadTreeNodeType
		{
			INTERMIDIATE_NODE,
			LEAF_NODE
		};

		QuadTree()
			:	topLeft(nullptr),
				topRight(nullptr),
				bottomLeft(nullptr),
				bottomRight(nullptr)
		{
			nodeType = LEAF_NODE;
		}

		// Inserting new node
		int insert(Body body);

		// building the tree for the first time
		int buildTree();

		// Balancing the tree after the peices have moved
		int rebalanceTree();

		// Get the list of bodies that are in the same leaf node
		// Broad phase collision detection
		int getClosest(Body body);

		// Get leaf list node list


		float xDiv;
		float yDiv;

		AABB treeBox;

		std::shared_ptr<QuadTree> topLeft;
		std::shared_ptr<QuadTree> topRight;
		std::shared_ptr<QuadTree> bottomLeft;
		std::shared_ptr<QuadTree> bottomRight;

		std::vector<std::shared_ptr<Body>> nodeBodyList;

		QuadTreeNodeType nodeType;

	private:

	};
}