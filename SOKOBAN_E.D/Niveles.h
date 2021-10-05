#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class Niveles
{
private:

	RenderWindow* pantallaJuego;


public:
	Niveles(int ancho, int alto, string titu);
};