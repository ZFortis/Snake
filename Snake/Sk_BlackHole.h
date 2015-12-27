#pragma once
#include "SDL_Sprite.h"
class Sk_BlackHole :
	public SDL_Sprite
{
public:
	Sk_BlackHole();
	~Sk_BlackHole();
	
public:
	void setRandomPosition(int minX, int minY, int maxX, int maxY);
};

