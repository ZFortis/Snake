#include "SDL.h"
#include "SDL_ttf.h"
#include"SDL_mixer.h"
#include"SDL_image.h"
#include"SDL_Sprite.h"
#include"Sk_Snake.h"
#include "Sk_BlackHole.h"
#include"Sk_Food.h"
#include"Sk_SnakeNode.h"
#include"Sk_Word.h"
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
	TTF_Init();
	SDL_Window *window = SDL_CreateWindow("Snake", 500, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Sk_Snake snake;
	Sk_SnakeNode sNode;
	Sk_Food food;
	SDL_Sprite bg;
	SDL_Event e;
	Uint32 start;
	Sk_BlackHole hole_1, hole_2;
	int score = 0;
	Sk_Word word;
	string text;
	int refershtime = 150;
	int level = 1;
	word.loadFont("./res/consola.ttf", 50);

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

	hole_1.loadImage(renderer, "./res/blackhole.png");
	hole_2.loadImage(renderer, "./res/blackhole.png");
	hole_1.setSprite(1, SNAKE_NODE_SIZE, SNAKE_NODE_SIZE);	
	hole_2.setSprite(1, SNAKE_NODE_SIZE, SNAKE_NODE_SIZE);

	hole_1.setRandomPosition(SNAKE_NODE_SIZE, SNAKE_NODE_SIZE, (SCREEN_WIDTH - SNAKE_NODE_SIZE) / 2 - SNAKE_NODE_SIZE, (SCREEN_HIGHT - SNAKE_NODE_SIZE) / 2 - SNAKE_NODE_SIZE);
	hole_2.setRandomPosition((SCREEN_WIDTH - SNAKE_NODE_SIZE) / 2, (SCREEN_HIGHT - SNAKE_NODE_SIZE) / 2, SCREEN_WIDTH - SNAKE_NODE_SIZE, SCREEN_HIGHT - SNAKE_NODE_SIZE);

	bg.loadImage(renderer, "./res/background.png");
	bg.setSprite(1, SCREEN_WIDTH, SCREEN_WIDTH);
	
	bool quite = false;
	start = SDL_GetTicks();
	string no = word.changeIntToString(level);
	word.setFontSize(50, 50);
	word.renderText(renderer, no, 50);
	SDL_RenderClear(renderer);
	word.setFontPosition((SCREEN_WIDTH - word.getWidth()) / 2, (SCREEN_HIGHT - word.getHight()) / 2);
	word.textureRenderer(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);

	text = word.changeIntToString(score);
	text = "Score: " + text;
	word.renderText(renderer, text, 50);
	word.setFontPosition(25, 0);
	word.setFontSize(100, 50);
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
		bg.textureRenderer(renderer);
		hole_1.textureRenderer(renderer);
		hole_2.textureRenderer(renderer);
		if (food.ifFoodBe())
			food.textureRendererColor(renderer);
			//food.textureRenderer(renderer);
		if (food.getPosX() == snake.getSnakeHeadX() && food.getPosY() == snake.getSnakeHeadY())
		{
			food.eatFood();
			snake.addSnakeNode(sNode,food.getColorFlag());
			score += 10;
			text = word.changeIntToString(score);
			text = "Score:  " + text;
			word.renderText(renderer, text, 50);
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
			if (hole_1.getPosX() == snake.getSnakeHeadX() && hole_1.getPosY() == snake.getSnakeHeadY())
			{
				snake.setSnakeHeadPoisition(hole_2.getPosX(), hole_2.getPosY());
			}

			else 	if (hole_2.getPosX() == snake.getSnakeHeadX() && hole_2.getPosY() == snake.getSnakeHeadY())
			{
				snake.setSnakeHeadPoisition(hole_1.getPosX(), hole_1.getPosY());
			}
		}

		word.textureRenderer(renderer);
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
			score = 0;
			text = word.changeIntToString(score);
			text = "Score:  " + text;
			word.renderText(renderer, text, 50);
		}
		if (score % 100 == 0 && score != 0)
		{
			snake.clearSnake();
			sNode.setSpritePosition(SCREEN_WIDTH / 2 - SNAKE_NODE_SIZE, SCREEN_HIGHT / 2 - SNAKE_NODE_SIZE);
			snake.setDirection();
			snake.addSnakeNode(sNode);
			snake.setSnakeLive();
			refershtime += 50;
			word.setFontSize(50, 50);
			level++;
			no = word.changeIntToString(level);
			word.renderText(renderer, no, 50);
			SDL_RenderClear(renderer);
			word.setFontPosition((SCREEN_WIDTH - word.getWidth()) / 2, (SCREEN_HIGHT - word.getHight()) / 2);
			word.textureRenderer(renderer);
			SDL_RenderPresent(renderer);			
			SDL_Delay(2000);
			score = 0;
			text = word.changeIntToString(score);
			text = "Score: " + text;
			word.renderText(renderer, text, 50);
			word.setFontPosition(25, 0);
			word.setFontSize(100, 50);
		}
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	//退出SDL 
	SDL_Quit();
	return 0;
}
