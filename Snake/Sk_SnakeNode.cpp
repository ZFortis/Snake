#include "Sk_SnakeNode.h"


Sk_SnakeNode::Sk_SnakeNode()
{
}


Sk_SnakeNode::~Sk_SnakeNode()
{
}

void Sk_SnakeNode::setRandomColor()
{
	int seed = (int)time(0);
	srand(seed);
	colorFlag = 0;
	colorFlag = rand() % 4;
}

void Sk_SnakeNode::setColorFlag(int colorFalg)
{
	this->colorFlag = colorFalg;
}

void Sk_SnakeNode::textureRendererColor(SDL_Renderer*renderer)
{
	textureRenderer(renderer, clip + colorFlag);
}

