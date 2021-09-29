#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Nodo
{
private:
	Nodo* siguiente;
	Nodo* anterior;
	Nodo* arriba;
	Nodo* abajo;
	int dato;
public:
	Nodo();
	Nodo(int,Nodo *,Nodo *,Nodo *,Nodo *);
	void setSig(Nodo* siguiente);
	void setAnt(Nodo* anterior);
	void setArriba(Nodo* arriba);
	void setAbajo(Nodo* abajo);
	void setDato(int dato);
};