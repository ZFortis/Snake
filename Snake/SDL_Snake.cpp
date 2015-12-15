#include "SDL_Snake.h"
using namespace::std;

SDL_Snake::SDL_Snake()
{
}


SDL_Snake::~SDL_Snake()
{
}

void SDL_Snake::moveSnake()
{
	int oldX = snake[0].getPosX();
	int oldY = snake[0].getPosY();
	int x = oldX;
	int y = oldY;
	switch (direction)
	{
	case 1:y -= 10; snake[0].setSpritePosition(x, y); break;
	case 2:y += 10; snake[0].setSpritePosition(x, y); break;
	case 3:x -= 10; snake[0].setSpritePosition(x, y); break;
	case 4:x += 10; snake[0].setSpritePosition(x, y); break;
	default:
		break;
	}

	for (int a = snake.size() - 1; a != 1 ; a--)
	{
		int x = snake[a - 1].getPosX();
		int y = snake[a - 1].getPosY();
		snake[a].setSpritePosition(x, y);
	}
	snake[1].setSpritePosition(oldX, oldY);
}

void SDL_Snake::drawSnake(SDL_Renderer*renderer)
{
	for (auto &a : snake)
	{
		a.textureRenderer(renderer);
	}
}

void SDL_Snake::controlSnake(SDL_Event e)
{
	oldDirection = direction;
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
			case SDLK_UP: if (oldDirection != 2) direction = 1; break;
			case SDLK_DOWN: if (oldDirection != 1) direction = 2;  break;
			case SDLK_LEFT: if (oldDirection != 4) direction = 3; break;
			case SDLK_RIGHT: if (oldDirection != 3) direction = 4; break;
			default:
				break;
		}
	}
}

void SDL_Snake::setDirection()
{
	direction = 2;
	oldDirection = direction;
}

void SDL_Snake::addSnakeNode(SDL_SnakeNode snakeNode)
{
	snake.push_back(snakeNode);
}