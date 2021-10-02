#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#define Max_menu 4//define la dimension del vector contenenedor de los botones del menu de opciones

using namespace sf;
using namespace std;

class Opciones{

private:

	int MenuSeleccionado;
	RenderWindow* menuOpciones;
	Texture* texturaFondo;
	Sprite* basePantalla;
	Event* evento;
	Font* fuente;
	Text* label;
	Text vectorBotones[Max_menu];
	
public:
	Opciones(int ancho, int alto, string titu);
	void gameloop();
	void dibujar();
	void ejecutar();
	~Opciones();

	int MenuPressed()
	{
		return MenuSeleccionado;
	}
};