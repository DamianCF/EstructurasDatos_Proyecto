#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Juego.h"
#include "SFML/Audio.hpp"

using namespace sf;
using namespace std;
#define maximoBotones 5

class Niveles{

	private:

		int nivelSeleccionado;
		RenderWindow* pantallaNiveles;
		Texture* textureBackground;
		Sprite* spritePantalla;
		Event* evento;
		Font* fuente;
		Text vectorNiveles[maximoBotones];

		Juego* game;

		SoundBuffer buffer;
		Sound click;

	public:
		Niveles(int ancho, int alto, string titu);
		~Niveles();

		void gameloopNiveles();
		void ejecutarBotones();
		void dibujarBotones();
		void moveArriba();
		void moveAbajo();

		int NivelPressed()
		{
			return nivelSeleccionado;
		}

};