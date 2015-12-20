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
	void setSnakeLive();
	void setSnakeDead();
	bool checkSnakeCollide();
	bool ifSnakeLife();

protected:
	bool ifLive;
	int direction;
	int oldDirection;
	vector<SDL_SnakeNode> snake;
};

