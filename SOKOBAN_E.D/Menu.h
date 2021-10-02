#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Juego.h"
#include "Opciones.h"
#include "AcercaDe.h"
using namespace sf;
using namespace std;

#define Max_menu 4

class Menu{
	private:

		int MenuSeleccionado;
		int fps;//cantidad de frames por segundo en que se actualiza la pantalla
	
		RenderWindow* menuPrincipal;//ventada que almacena el menu principal de la aplicacion
		Texture* texturaFondo;
		Sprite* basePantalla;
		Event* evento; 
		Juego* game;
		Opciones* options;
		AcercaDe* info;
		Font *fuente;
		Text vectorBotones[Max_menu];

	
	

	public:
		Menu(int ancho, int alto, string titulo);
		~Menu();
		void gameloop();
		void dibujar();
		void ejecutarEventos();
		void MoverArriba();
		void Moverabajo();

		int MenuPressed()
		{
			return MenuSeleccionado;
	    }

	
	
};