#pragma once
#include"Parallelogram.h"
class Diamond : virtual public Parallelogram
{
public:
	Diamond();
	Diamond(Point, int, double);
	~Diamond();
};

