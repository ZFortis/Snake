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
	//�ж�ʳ���Ƿ����
	bool ifFoodBe();																				
	//ʳ�ﱻ��
	void eatFood();
	//����һ������
	void creatFood();
	//�������λ��
	void setRandomPosition(int minX,int minY,int maxX, int maxY);
	//���������ɫ
	void setRandomColor();
	//���Ʋ�ͬ��ɫ
	void textureRendererColor(SDL_Renderer*renderer);
	//�õ���ɫ��ʶ
	int getColorFlag();

protected:
	/*ʳ���Ƿ��+��*/
	bool ifBe;
	int colorFlag;
};

