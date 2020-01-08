#pragma once
#pragma once
#include "Object.h"

class House :public Object
{
public:
	House(const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
		friend House;
		Base(const Transform& transform);
	}m_base;

	

	
};

