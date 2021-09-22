#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Juego.h"
#include "Opciones.h"
using namespace sf;
using namespace std;

#define Max_menu 4
class Menu
{
private:
	RenderWindow* ventana1;
	int fps;
	Texture* background;
	Sprite* sprite1;
	Event* evento1;
	Juego* game;
	Opciones* options;

	int MenuSeleccionado;
	Font *fuente;
	Text *label1;
	Text *label2;
	Text *label3;
	Text *label4;
	Text pv[Max_menu];

public:
	Menu(int ancho, int alto, string titulo);
	void gameloop();
	void dibujar();
	void ejecutar_eventos();

	void MoverArriba();
	void Moverabajo();

	int MenuPressed()
	{
		return MenuSeleccionado;
	}
	~Menu();
};