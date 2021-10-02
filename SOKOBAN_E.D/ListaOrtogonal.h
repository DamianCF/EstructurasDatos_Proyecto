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
public:
	ListaOrtogonal();
	void crear(int n, int m, Nodo*&);
	void desplegar(Nodo*);
	void cargarNivel(string lvlName);
	void cargarVec();
private:
	//nodo *head;
	//char matriz[fil][col];
	char* vec;
};

