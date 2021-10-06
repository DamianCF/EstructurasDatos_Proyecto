#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "ListaOrtogonal.h"
#include <vector>
#include <time.h>



using namespace sf;
using namespace std;

class Juego
{
	private:
		RenderWindow* pantallaJuego;
	
		Nodo* head;
		Nodo* head2;
		ListaOrtogonal* obj;

		Texture* texturaFondo;
		Sprite* fondoPantalla;
		Event* evento;
		Font* fuente;
		Text* label1;

		Texture* Tmuros;
		Sprite* Smuro;

		Texture* Tpiso;
		Sprite* Spiso;

		Texture* Tpersonaje;
		Sprite* Spersonaje;

		vector<char> repeticion;

	public:
		Juego(int ancho, int alto, string titu, string nivel);
		void gameloop(string nivel);
		void dibujar();
		void ejecutar();

		void crearGrid(string nivel);
		void crearGridCopia(string nivel);
		void actualizaMapa(char caracter, float x, float y, Texture* Tmuros, Sprite* Smuro);
		void cargaMapa(Nodo* head);
		void cargaBaseMapa(char caracter, float x, float y, Texture* Tmuros, Sprite* Smuro);

		void MoverArriba(int num);
		void moverAbajo(int num);
		void moverDerecha(int num);
		void moverIzquierda(int num);

		void moverRep(int num);
		void borrarRep();
		void verRepeticion();
		vector<char> rep();

		~Juego();


};
