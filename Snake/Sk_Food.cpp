#include "Sk_Food.h"


Sk_Food::Sk_Food()
{
}


Sk_Food::~Sk_Food()
{
}

void Sk_Food::setRandomPosition(int minX,int minY,int maxX, int maxY)
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

bool Sk_Food::ifFoodBe()
{
	return ifBe;
}

void Sk_Food::eatFood()
{
	ifBe = false;
}

void Sk_Food::creatFood()
{
	ifBe = true;
}

void Sk_Food::setRandomColor()
{
	int seed = (int)time(0);
	srand(seed);
	colorFlag = 0;
	colorFlag = rand() % 4;
}

void Sk_Food::textureRendererColor(SDL_Renderer*renderer)
{
	textureRenderer(renderer, clip + colorFlag);
}

int Sk_Food::getColorFlag()
{
	return colorFlag;
}