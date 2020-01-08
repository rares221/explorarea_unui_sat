#pragma once
#pragma once
#pragma once
#include "Object.h"

class Castle :public Object
{
public:
	Castle(const Transform& transform = Transform());
	void UpdateThenDraw(const Camera& camera) override;

private:
	class Base :public Object
	{
		friend Castle;
		Base(const Transform& transform);
	}m_base;




};

