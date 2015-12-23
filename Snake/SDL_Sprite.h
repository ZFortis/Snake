#pragma once
#include "SDL.h"
#include"SDL_image.h"
class SDL_Sprite
{
public:
	SDL_Sprite();
	~SDL_Sprite();

public:
	//����ͼƬ
	void loadImage(SDL_Renderer*renderer, const char*file);									
	//����ͼƬ
	void textureRenderer(SDL_Renderer*renderer);													
	//����ͼƬ
	void textureRenderer(SDL_Renderer*renderer, SDL_Rect *clip);							
	//����ͼƬ
	void textureRenderer(SDL_Renderer*renderer, SDL_Rect*clip, int x, int y);			
	//����ͼƬ
	void textureRenderer(SDL_Renderer*renderer, int x, int y);								
	//����λ��
	void setSpritePosition(int x, int y);																		
	//���òü�����
	void setSprite(int n, int w, int h);																	
	//���þ���
	void setRect(int x, int y, int w, int h);																
	
	//����ͼƬ���
	int getWidth();																								
	//����ͼƬ�߶�
	int getHight();																								
	//����x����
	int getPosX();																									
	//����y����
	int getPosY();																									

protected:
	SDL_Texture*tex;
	//�ü�����
	SDL_Rect*clip;																									
	//ͼƬ���
	int w;																											
	//ͼƬ�߶�
	int h;																												
	//ͼƬx������
	int x;																													
	//ͼƬy������
	int y;																													
	//������
	int spriteW;																										
	//����߶�
	int spriteH;																										
};

