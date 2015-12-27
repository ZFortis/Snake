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
	//�ƶ���
	void moveSnake();
	//������
	void controlSnake(SDL_Event e);
	//������
	void controlSnake(int ek);
	//�����ߵĽڵ�
	void addSnakeNode(Sk_SnakeNode snakeNode);
	//�����ߵĽڵ�
	void addSnakeNode(Sk_SnakeNode snakeNode, int colorFlag);
	//�����ߵĽڵ�
	void addSnakeNode();
	//�����ߵĵĽڵ�
	void addSnakeNode(int flag);
	//������
	void drawSnake(SDL_Renderer*renderer);
	//���Ʋ�ɫ����
	void drawColorSnake(SDL_Renderer*renderer);
	//�����ߵķ���
	void setDirection();
	//������Ϊ��
	void setSnakeLive();
	//������Ϊ��
	void setSnakeDead();
	//�����
	void clearSnake();
	//��ײ���
	bool checkSnakeCollide();
	//����������
	bool ifSnakeLife();
	//�õ���ͷ��x����
	int getSnakeHeadX();
	//�õ���ͷ��y����
	int getSnakeHeadY();
	//������ͷ��x����
	void setSnakeHeadX(int x);
	//������ͷ��y����
	void setSnakeHeadY(int y);
	//������ͷ����
	void setSnakeHeadPoisition(int x, int y);

protected:
	//�ߵ�����
	bool ifLive;
	//�ߵķ���
	int direction;
	//�ߵ���һ������
	int oldDirection;
	//��
	vector<Sk_SnakeNode> snake;

};

