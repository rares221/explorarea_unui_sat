#pragma once
#pragma once
#pragma once
#include "Object.h"

class Tree :public Object
{
public:
	Tree(const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

private:
	class tree :public Object
	{
		friend Tree;
		tree(const Transform& transform);
	}m_tree;




};

#pragma once
