#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;

class AcercaDe
{
	private:
		RenderWindow* pantallaInfo;//ventada que almacena el menu principal de la aplicacion
		Texture* texturaFondo;
		Sprite* basePantalla;
		Event* evento;
	public:
		AcercaDe(int ancho, int alto, string titulo);
		void gameloop();
		void dibujar();
		void ejecutarEventos();
};

