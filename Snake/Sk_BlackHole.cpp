#include "Sk_BlackHole.h"
#include<ctime>
#include<cstdlib>

Sk_BlackHole::Sk_BlackHole()
{
}


Sk_BlackHole::~Sk_BlackHole()
{
}

void Sk_BlackHole::setRandomPosition(int minX, int minY, int maxX, int maxY)
{
	int seed = time(0);
	srand(seed);
	int x = rand() % maxX;
	int y = rand() % maxY;
	x /= 10;
	x *= 10;
	y /= 10;
	y *= 10;
	if (x == 0)
		x += minX;
	if (y == 0)
		y += minY;
	this->x = x;
	this->y = y;
}
