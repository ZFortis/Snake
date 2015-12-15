#pragma once
#include<vector>
#include"SDL_SnakeNode.h"
using namespace std;
class SDL_Snake
{
public:
	SDL_Snake();
	~SDL_Snake();

public:
	void moveSnake();
	void controlSnake(SDL_Event e);
	void addSnakeNode(SDL_SnakeNode snakeNode);
	void drawSnake(SDL_Renderer*renderer);
	void setDirection();

protected:
	int direction;
	int oldDirection;
	vector<SDL_SnakeNode> snake;
};

