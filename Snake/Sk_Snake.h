#pragma once
#include<vector>
#include"Sk_SnakeNode.h"
using namespace std;
class Sk_Snake
{
public:
	Sk_Snake();
	~Sk_Snake();

public:
	//移动蛇
	void moveSnake();
	//控制蛇
	void controlSnake(SDL_Event e);
	//控制蛇
	void controlSnake(int ek);
	//增加蛇的节点
	void addSnakeNode(Sk_SnakeNode snakeNode);
	//增加蛇的节点
	void addSnakeNode(Sk_SnakeNode snakeNode, int colorFlag);
	//增加蛇的节点
	void addSnakeNode();
	//增加蛇的的节点
	void addSnakeNode(int flag);
	//绘制蛇
	void drawSnake(SDL_Renderer*renderer);
	//绘制彩色的蛇
	void drawColorSnake(SDL_Renderer*renderer);
	//设置蛇的方向
	void setDirection();
	//设置蛇为生
	void setSnakeLive();
	//设置蛇为死
	void setSnakeDead();
	//清空蛇
	void clearSnake();
	//碰撞检测
	bool checkSnakeCollide();
	//蛇是生是死
	bool ifSnakeLife();
	//得到蛇头的x坐标
	int getSnakeHeadX();
	//得到蛇头的y坐标
	int getSnakeHeadY();
	//设置蛇头的x坐标
	void setSnakeHeadX(int x);
	//设置蛇头的y坐标
	void setSnakeHeadY(int y);
	//设置蛇头坐标
	void setSnakeHeadPoisition(int x, int y);

protected:
	//蛇的生死
	bool ifLive;
	//蛇的方向
	int direction;
	//蛇的上一个方向
	int oldDirection;
	//蛇
	vector<Sk_SnakeNode> snake;

};

