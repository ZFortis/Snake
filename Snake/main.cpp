#include "SDL.h"
#include "SDL_ttf.h"
#include"SDL_mixer.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"SDL_Snake.h"
#include"SDL_SnakeNode.h"
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<time.h>
#include<cmath>
#include "SDL_EffectSound.h"
/*
����1���ܿ���̰�����ƶ�����Ʒ���ӳ��ȣ�
����2����Ʒ���Ͷ������Ե���ͬ��Ʒ������β����ʾ��ͬ��Ʒ��
����3���ڳ����о��ж���̰���߽������Դ���������������
����4����̰�������һ�����Ⱥ������һ�أ���һ���ٶ����ӣ��ܹ�����5�أ�
����5��̰����������ǽ��������ʾ��Ϸʧ�ܣ�
*/
/*620*460*/
const int SCRRN_WIDTH = 640;
const int SCREEN_HIGHT = 480;
const int SNAKE_NODE_SIZE = 10;
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Snake", 500, 100, SCRRN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Snake snake;
	SDL_SnakeNode sNode;
	SDL_Event e;
	Uint32 start;
	sNode.loadImage(renderer,"snakeHead.png");
	sNode.setSprite(1, SNAKE_NODE_SIZE, SNAKE_NODE_SIZE);
	sNode.setSpritePosition(0, 50);
	snake.setDirection();
	snake.addSnakeNode(sNode);
	for (int i = 0; i < 10; i++)
	{
		sNode.setSpritePosition(0, 50 - 10 * (i + 1));
		snake.addSnakeNode(sNode);
	}
	bool quite = false;
	start = SDL_GetTicks();
	while (!quite)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quite = true;

			snake.controlSnake(e);
		}
		if (quite)
			continue;

		SDL_RenderClear(renderer);
		snake.drawSnake(renderer);
		if (SDL_GetTicks() - start >= 100)
		{
			snake.moveSnake();
			start = SDL_GetTicks();
		}
		SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//�˳�SDL 
	SDL_Quit();
	return 0;
}
