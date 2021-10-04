#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "ListaOrtogonal.h"


using namespace sf;
using namespace std;

class Juego
{
	private:
		RenderWindow* pantallaJuego;
	
		Nodo* head;
		ListaOrtogonal* obj;

		Texture* background;
		Sprite* sprite1;
		Event* evento;
		Font* fuente;
		Text* label1;

		Texture* Tmuros;
		Sprite* Smuro;

		Texture* Tpiso;
		Sprite* Spiso;

		Texture* Tpersonaje;
		Sprite* Spersonaje;

	public:
		Juego(int ancho, int alto, string titu);
		void gameloop();
		void dibujar();
		void ejecutar();

		void crearGrid();
		void actualizaMapa(char caracter, int x, int y, Texture* Tmuros, Sprite* Smuro);
		void cargaMapa(Nodo* head);
		void cargaBaseMapa(char caracter, int x, int y, Texture* Tmuros, Sprite* Smuro);
		~Juego();


};
