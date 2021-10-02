#include "SFML/Graphics.hpp"
#include "iostream"
#include "Menu.h"
#include "Nodo.h"
#include "ListaOrtogonal.h"
using namespace sf;
using namespace std;

Nodo* head;
ListaOrtogonal* obj;
int main(int argc, char* args[])
{
	obj = new ListaOrtogonal();
	obj->cargarNivel("Mapas/Nivel1.txt");
	obj->crear(4, 4, head);
	obj->desplegar(head);
	obj->cargarVec();
	Menu* partida;
	partida = new Menu(960, 540, "SOKOBAN");
	
	return 0;
}
