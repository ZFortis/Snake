#include "Sk_Snake.h"
using namespace::std;

Sk_Snake::Sk_Snake()
{
}


Sk_Snake::~Sk_Snake()
{
}

void Sk_Snake::moveSnake()
{
	int oldX = snake[0].getPosX();
	int oldY = snake[0].getPosY();
	int x = oldX;
	int y = oldY;
	
	for (int a = snake.size() - 1; a >= 1 ; a--)
	{
		int x = snake[a - 1].getPosX();
		int y = snake[a - 1].getPosY();
		snake[a].setSpritePosition(x, y);
	}

	switch (direction)
	{
	case 1:y -= 10; snake[0].setSpritePosition(x, y); break;
	case 2:y += 10; snake[0].setSpritePosition(x, y); break;
	case 3:x -= 10; snake[0].setSpritePosition(x, y); break;
	case 4:x += 10; snake[0].setSpritePosition(x, y); break;
	default:
		break;
	}

//	snake[1].setSpritePosition(oldX, oldY);
}

void Sk_Snake::drawSnake(SDL_Renderer*renderer)
{
	for (auto &a : snake)
	{
		a.textureRenderer(renderer);
	}
}

void Sk_Snake::drawColorSnake(SDL_Renderer*renderer)
{
	for (auto &a : snake)
	{
		a.textureRendererColor(renderer);
	}
}

void Sk_Snake::controlSnake(SDL_Event e)
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


void Sk_Snake::controlSnake(int ek)
{
	oldDirection = direction;
	switch (ek)
	{
	case 1: if (oldDirection != 2) direction = 1; break;
	case 2: if (oldDirection != 1) direction = 2;  break;
	case 3: if (oldDirection != 4) direction = 3; break;
	case 4: if (oldDirection != 3) direction = 4; break;
	default:
		break;
	}

}

void Sk_Snake::setDirection()
{
	direction = 2;
	oldDirection = direction;
}

void Sk_Snake::addSnakeNode(Sk_SnakeNode snakeNode)
{
	if (!snake.empty())
	switch (direction)
	{
	case 1:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX(), snake[snake.size() - 1].getPosY() + 10); break;
	case 2:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX(), snake[snake.size() - 1].getPosY() - 10); break;
	case 3:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX() + 10, snake[snake.size() - 1].getPosY()); break;
	case 4:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX() - 10, snake[snake.size() - 1].getPosY()); break;
	default:break;
	}
	snake.push_back(snakeNode);
}

void Sk_Snake::addSnakeNode()
{
	
}

void Sk_Snake::addSnakeNode(int flag)
{

}

void Sk_Snake::setSnakeLive()
{
	ifLive = true;
}

void Sk_Snake::setSnakeDead()
{
	ifLive = false;
}

void Sk_Snake::clearSnake()
{
	snake.clear();
}

bool Sk_Snake::checkSnakeCollide()
{
	for (int i = 1; i != snake.size(); i++)
	{
		if (snake[i].getPosX() == snake[0].getPosX() && snake[i].getPosY() == snake[0].getPosY())
			return false;
	}
	switch (direction)
	{
	case 1:if (snake[0].getPosY() < 10)
		return false; break;
	case 2:if (snake[0].getPosY() > 460)
		return false; break;
	case 3:if (snake[0].getPosX() < 10)
		return false; break;
	case 4:if (snake[0].getPosX() > 620)
		return false; break;
	}
	return true;
}

bool Sk_Snake::ifSnakeLife()
{
	return ifLive;
}

int Sk_Snake::getSnakeHeadX()
{
	return snake[0].getPosX();
}

int Sk_Snake::getSnakeHeadY()
{
	return snake[0].getPosY();
}

void Sk_Snake::addSnakeNode(Sk_SnakeNode snakeNode, int colorFlag)
{
	snakeNode.setColorFlag(colorFlag);
	if (!snake.empty())
		switch (direction)
	{
		case 1:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX(), snake[snake.size() - 1].getPosY() + 10); break;
		case 2:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX(), snake[snake.size() - 1].getPosY() - 10); break;
		case 3:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX() + 10, snake[snake.size() - 1].getPosY()); break;
		case 4:snakeNode.setSpritePosition(snake[snake.size() - 1].getPosX() - 10, snake[snake.size() - 1].getPosY()); break;
		default:break;
	}
	snake.push_back(snakeNode);
}

void Sk_Snake::setSnakeHeadX(int x)
{
	snake[0].setSpritePosition(x, snake[0].getPosY());
}

void Sk_Snake::setSnakeHeadY(int y)
{
	snake[0].setSpritePosition(snake[0].getPosX(),y);
}

void Sk_Snake::setSnakeHeadPoisition(int x, int y)
{
	snake[0].setSpritePosition(x, y);
}