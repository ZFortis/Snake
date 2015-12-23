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
	//���������ɫ
	void setRandomColor();
	//���Ʋ�ͬ��ɫ
	void textureRendererColor(SDL_Renderer*renderer);
	//������ɫ��ʶ
	void setColorFlag(int colorFalg);

protected:
	int colorFlag;
};

