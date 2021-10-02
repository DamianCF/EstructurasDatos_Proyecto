#include "ListaOrtogonal.h"
ListaOrtogonal::ListaOrtogonal() {
	vec = new char[(fil * col)];
}

void ListaOrtogonal::crear(int n, int m, Nodo*& head)
{
	Nodo* p = NULL, * q = NULL, * r = NULL;
	int i, j, k = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			p = new Nodo();
			p->setDato(vec[k]);
			p->setSig(NULL);
			p->setAbajo(NULL);
			if (j == 1)
			{
				p->setAnt(NULL);
				if (head == NULL) {
					head = p;
				}
				q = p;
				//j+=1;
			}
			else
			{
				p->setAnt(q);;
				p->setSig(p);
				q = p;
			}
			if (i == 1)
			{
				p->setArriba(NULL);
				q = p;

			}
			else
			{
				p->setArriba(r);
				r->setAbajo(p);
				r = r->getSig();
			}
			k++;
		}
		r = head;
		while (r->getAbajo() != NULL)
			r = r->getAbajo();
	}
}


void ListaOrtogonal::desplegar(Nodo* head)
{
	//cout<<"El dato es: "<<head->dato<<endl;
	Nodo* p = NULL, * q = NULL;
	if (head != NULL)
	{
		p = head;
		while (p != NULL)
		{
			q = p;
			while (q != NULL)
			{
				cout << q->getDato() << " ";
				q = q->getSig();
			}
			cout << endl;
			p = p->getAbajo();
		}
	}
	else
		cout << "Lista vacia...";
}

void ListaOrtogonal::cargarNivel(string lvlName)
{
	/*int i=0;
	FILE *ab;
	char caracter;
	stringstream ss;
	ss<<"Nivel"<<lvlName<<".txt";
	string url=ss.str();
	int nu=url.length();
	char direccion[nu+1];
	strcpy(direccion,url.c_str());
	ab = fopen(direccion,"r");
	if (ab == NULL){
		cout<<"\nError de apertura del archivo. \n\n";
	}else{
		cout<<"\nEl contenido del archivo de prueba es \n\n";
		while (feof(ab) == 0){
			caracter = fgetc(ab);
			//cout<<caracter;
			vec[i]=caracter;
			i++;
		}
	}
	fclose(ab);*/

	int i = 0, j = 0;
	char c;
	ifstream inFile;
	inFile.open(lvlName.c_str());
	inFile >> noskipws;

	if (!inFile)
	{
		cout << "Error al cargar el nivel" << endl;
		exit(1);
	}
	else
	{
		while (!inFile.eof())
		{
			inFile.get(c);
			if (c != '\n')
			{
				vec[i] = c;
				i++;
			}
		}

		inFile.close();
	}
}

void ListaOrtogonal::cargarVec()
{
	for (int i = 0;i < 16;i++) {
		cout << vec[i];
		//cout<<endl;
	}
}
