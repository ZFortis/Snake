#pragma once
#include<ctime>
#include<cstdlib>
#include "SDL_Sprite.h"
class Sk_Food:
	public SDL_Sprite
{
public:	
	Sk_Food();
	~Sk_Food();
public:
	//判断食物是否存在
	bool ifFoodBe();																				
	//食物被吃
	void eatFood();
	//创造一个事物
	void creatFood();
	//设置随机位置
	void setRandomPosition(int minX,int minY,int maxX, int maxY);
	//设置随机颜色
	void setRandomColor();
	//绘制不同颜色
	void textureRendererColor(SDL_Renderer*renderer);
	//得到颜色标识
	int getColorFlag();

protected:
	/*食物是否存+在*/
	bool ifBe;
	int colorFlag;
};

