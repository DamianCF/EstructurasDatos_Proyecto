#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <sstream>
#include "Nodo.h"

using namespace std;
#define fil 4
#define col 4

class ListaOrtogonal
{
private:
	char* vec;
public:
	ListaOrtogonal();
	void cargarLista(int n, int m, Nodo*&);
	void desplegar(Nodo*);
	void cargarNivel(string lvlName);
	void cargarVec();

};

