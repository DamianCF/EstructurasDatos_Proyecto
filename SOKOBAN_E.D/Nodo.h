#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Nodo
{
public:
	Nodo(int dato, Nodo *sig, Nodo *ant, Nodo *ar, Nodo *ab);
	void setSig(Nodo* sig);
	void setAnt(Nodo* ant);
	void setArriba(Nodo* ar);
	void setAbajo(Nodo* ab);
private:
	Nodo* siguiente;
	Nodo* anterior;
	Nodo* arriba;
	Nodo* abajo;
	int dato;
};