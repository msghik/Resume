#include "Diamond.h"



Diamond::Diamond()
{
}

Diamond::Diamond(Point p1, int a, double teta) :Parallelogram(p1, a, a, teta)
{
	setParallelogram(p1, a, a, teta);
}


Diamond::~Diamond()
{
}
