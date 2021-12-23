#include "Square.h"



Square::Square()
{

}

Square::Square(Point p, int a):Rectangle(p,a,a),Diamond(p,a,2*atan(1)){
	
}

Square::~Square()
{
}




double Square::totalAngels()
{
	return 360.0;
}
