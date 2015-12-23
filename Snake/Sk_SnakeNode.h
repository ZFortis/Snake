#pragma once
#include<ctime>
#include<cstdlib>
#include "SDL_Sprite.h"
class Sk_SnakeNode :
	public SDL_Sprite
{
public:
	Sk_SnakeNode();
	~Sk_SnakeNode();

public:
	//设置随机颜色
	void setRandomColor();
	//绘制不同颜色
	void textureRendererColor(SDL_Renderer*renderer);
	//设置颜色标识
	void setColorFlag(int colorFalg);

protected:
	int colorFlag;
};

