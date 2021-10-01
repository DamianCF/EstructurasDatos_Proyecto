#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Opciones
{

private:
	RenderWindow* ventana3;
	Texture* background;
	Sprite* sprite1;
	Event* evento;

	Font* fuente;
	Text* label;
	
public:
	Opciones(int ancho, int alto, string titu);
	void gameloop();
	void dibujar();
	void ejecutar();
	~Opciones();

};