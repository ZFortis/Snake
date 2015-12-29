#include "Sk_Word.h"
using namespace std;

Sk_Word::Sk_Word()
{
}


Sk_Word::~Sk_Word()
{
}

void Sk_Word::loadFont(string name, int size)
{
	font = TTF_OpenFont(name.c_str(), 50);
}

void Sk_Word::renderText(SDL_Renderer*renderer, string text, int size)
{
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
	tex = SDL_CreateTextureFromSurface(renderer, surf);
	//Clean up unneeded stuff
	SDL_FreeSurface(surf);
	//TTF_CloseFont(font);
}

void Sk_Word::textureRenderer(SDL_Renderer*renderer)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = w;
	dst.h = h;
	SDL_RenderCopy(renderer, tex, NULL, &dst);
}

void Sk_Word::setFontPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Sk_Word::setFontSize(int w, int h)
{
	this->w = w;
	this->h = h;
}

int Sk_Word::getPosX()
{
	return x;
}

int Sk_Word::getPosY()
{
	return y;
}

int Sk_Word::getWidth()
{
	return w;
}

int Sk_Word::getHight()
{
	return h;
}

string Sk_Word::changeIntToString(int num)
{
	string s;
	std::stringstream ss;
	ss << num;
	ss >> s;
	return s;
}
