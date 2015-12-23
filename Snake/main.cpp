#include "SDL.h"
#include "SDL_ttf.h"
#include"SDL_mixer.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"Sk_Snake.h"
#include"Sk_Food.h"
#include"Sk_SnakeNode.h"
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
const int SCREEN_WIDTH = 640;
const int SCREEN_HIGHT = 480;
const int SNAKE_NODE_SIZE = 10;
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Snake", 500, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Sk_Snake snake;
	Sk_SnakeNode sNode;
	Sk_Food food;
	SDL_Event e;
	Uint32 start;
	food.loadImage(renderer, "./res/nodeSprite.png");
	food.setSprite(4, SNAKE_NODE_SIZE, SNAKE_NODE_SIZE);
	food.setRandomPosition(2 * SNAKE_NODE_SIZE, 2 * SNAKE_NODE_SIZE,SCREEN_WIDTH - 10, SCREEN_HIGHT - 20);
	food.setRandomColor();
	food.creatFood();

	sNode.loadImage(renderer,"./res/nodeSprite.png");
	sNode.setRandomColor();
	sNode.setSprite(4, SNAKE_NODE_SIZE, SNAKE_NODE_SIZE);
	sNode.setSpritePosition(SCREEN_WIDTH / 2 - SNAKE_NODE_SIZE, SCREEN_HIGHT / 2 - SNAKE_NODE_SIZE);
	snake.setDirection();
	snake.addSnakeNode(sNode);
	snake.setSnakeLive();

	bool quite = false;
	start = SDL_GetTicks();
	while (!quite)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quite = true;

			/*if (e.type == SDL_KEYDOWN)
			{
			if (snake.snake.size() == 3)
			{
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
			snake.controlSnake(e);
			break;
			}
			}*/
			if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP : snake.controlSnake(1); break;
				case SDLK_DOWN: snake.controlSnake(2); break;
				case SDLK_LEFT: snake.controlSnake(3); break;
				case SDLK_RIGHT: snake.controlSnake(4); break;
				default:
					break;
				}
				break;
			}
			//break;
		}
	
		if (quite)
			continue;

		SDL_RenderClear(renderer);
		if (food.ifFoodBe())
			food.textureRendererColor(renderer);
			//food.textureRenderer(renderer);
		if (food.getPosX() == snake.getSnakeHeadX() && food.getPosY() == snake.getSnakeHeadY())
		{
			food.eatFood();
			snake.addSnakeNode(sNode,food.getColorFlag());
		}
		if (!food.ifFoodBe())
		{
			food.setRandomPosition(2 * SNAKE_NODE_SIZE, 2 * SNAKE_NODE_SIZE, SCREEN_WIDTH - 2 * SNAKE_NODE_SIZE, SCREEN_HIGHT - 2 * SNAKE_NODE_SIZE);
			food.setRandomColor();
			food.creatFood();
		}
		snake.drawColorSnake(renderer);
		if (SDL_GetTicks() - start >= 150)
		{
			snake.moveSnake();
			start = SDL_GetTicks();
		}
		SDL_RenderPresent(renderer);
		if (!snake.checkSnakeCollide())
			if (!snake.checkSnakeCollide())
				snake.setSnakeDead();
		if (!snake.ifSnakeLife())
		{
			snake.clearSnake();
			sNode.setSpritePosition(SCREEN_WIDTH / 2 - SNAKE_NODE_SIZE, SCREEN_HIGHT / 2 - SNAKE_NODE_SIZE);
			snake.setDirection();
			snake.addSnakeNode(sNode);
			snake.setSnakeLive();
		}
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//退出SDL 
	SDL_Quit();
	return 0;
}
