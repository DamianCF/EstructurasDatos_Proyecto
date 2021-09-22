#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
//#include "Menu.h"

using namespace sf;
using namespace std;

class Juego
{
public:
	Juego(int ancho,int alto, string titu);
	void gameloop();
	void dibujar();
	void ejecutar();
	void crearGrid();
	~Juego();

private:
	RenderWindow* ventana2;
	//Menu* backmain;
	Texture* background;
	Sprite* sprite1;
	Event* evento;

	Font* fuente;
	Text* label1;


};
