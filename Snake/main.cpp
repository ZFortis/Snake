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
功能1：能控制贪吃蛇移动吃物品增加长度；
功能2：物品类型多样，吃到不同物品可以在尾部显示不同物品；
功能3：在场景中具有洞，贪吃蛇进入后可以从其他洞中爬出；
功能4：当贪吃蛇完成一定长度后进入下一关，下一关速度增加，总共设置5关；
功能5：贪吃蛇碰到边墙会死，显示游戏失败；
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
	//退出SDL 
	SDL_Quit();
	return 0;
}
