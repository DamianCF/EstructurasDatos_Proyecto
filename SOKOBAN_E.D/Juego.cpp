#include "Juego.h"
#include "Menu.h"

Juego::~Juego()
{
}

Juego::Juego(int ancho, int alto, string titu)
{
	pantallaJuego = new RenderWindow(VideoMode(ancho, alto), titu);

	texturaFondo = new Texture;
	fondoPantalla = new Sprite;
	texturaFondo->loadFromFile("resource/fondoLadrillos.jpg");
	fondoPantalla->setTexture(*texturaFondo);
	fondoPantalla->setScale(((float)pantallaJuego->getSize().x / fondoPantalla->getTexture()->getSize().x), ((float)pantallaJuego->getSize().y / fondoPantalla->getTexture()->getSize().y));

	/*
	Tmuros = new Texture;
	Tmuros->loadFromFile("resource/1.png");
	IntRect posicion(1408,768 , 128, 128);
	Smuro = new Sprite;
	Smuro->setTextureRect(posicion);
	Smuro->setTexture(*Tmuros);*/
	//Smuro->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);
	//Smuro->setPosition(580, 200);

	evento = new Event;

	fuente = new Font();
	fuente->loadFromFile("fonts/PressStart2P-Regular.ttf");


	label1 = new Text();
	label1->setFont(*fuente);
	label1->setFillColor(Color::White);
	label1->setString("JUDANDO...");
	label1->setCharacterSize(40);
	label1->setPosition(300, 100);

	gameloop();
}

void Juego::gameloop()
{

	crearGrid();

	while (pantallaJuego->isOpen())
	{
		ejecutar();
		dibujar();
	}
}

void Juego::dibujar()
{



}

void Juego::ejecutar()
{
	while (pantallaJuego->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			pantallaJuego->close();
			exit(1);
		}
		if (evento->type == Event::KeyReleased)
		{
			if (evento->key.code == Keyboard::Escape)
			{
				Menu* backmain;
				pantallaJuego->close();
				backmain = new Menu(960, 540, "SOKOBAN");
			}
			if (evento->key.code == Keyboard::W)
			{
				Mover();
			}
		}
	}
}

void Juego::crearGrid()
{
	pantallaJuego->draw(*fondoPantalla);

	obj = new ListaOrtogonal();
	obj->cargarNivel("Mapas/Nivel1.txt");
	obj->cargarLista(9, 9, head);
	cargaMapa(head);
	cout << "Base cargada";
	pantallaJuego->display();
}

void Juego::actualizaMapa(char caracter, float x, float y, Texture* Tmuros, Sprite* Smuro) {
	
	//$ cajas
	if (caracter == '$') {
		IntRect posicion(128, 256, 128, 128);
		Smuro->setTextureRect(posicion);
	}

	//@ personaje
	if (caracter == '@') {
		IntRect posicion(0, 640, 128, 128);
		Smuro->setTextureRect(posicion);
	}

	Smuro->setPosition(x, y);
	pantallaJuego->draw(*Smuro);
}

void Juego::cargaBaseMapa(char caracter, float x, float y, Texture* Tmuros, Sprite* Smuro) {

	IntRect posicion(1408, 768, 128, 128);
	Smuro->setTextureRect(posicion);
	Smuro->setPosition(x, y);
	pantallaJuego->draw(*Smuro);

	//# paredes
	if (caracter == '#') {
		IntRect posicion(1152, 768, 128, 128);
		Smuro->setTextureRect(posicion);
	}
	//. metas
	if (caracter == '.') {
		IntRect posicion(1408, 896, 128, 128);
		Smuro->setTextureRect(posicion);
	}
	Smuro->setPosition(x, y);
	pantallaJuego->draw(*Smuro);
}

void Juego::cargaMapa(Nodo* head) {

	cout << "cargar mapa" << endl;
	

	Tmuros = new Texture();
	Smuro = new Sprite;

	Tmuros->loadFromFile("resource/1.png");
	Smuro->setTexture(*Tmuros);
	Smuro->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);

	Nodo* aux1 = NULL, * aux2 = NULL, * aux3 = NULL ;

	float x = 200;
	float y = 50;
	if (head != NULL)
	{
		aux1 = head;
		while (aux1 != NULL)
		{
			aux2 = aux1;
			while (aux2 != NULL)
			{
				cargaBaseMapa(aux2->getDato(), x, y, Tmuros, Smuro);
				actualizaMapa(aux2->getDato(), x, y, Tmuros, Smuro);
				
				aux2 = aux2->getSig();
				x = x + 62;
			}
			x = 200;
			aux1 = aux1->getAbajo();
			y = y + 50;
		}
	}
}

void Juego::Mover()
{
	Nodo* p = NULL, * q = NULL,*arri = NULL, *arri2 = NULL;
	if (head != NULL)
	{
		p = head;
		while (p != NULL)
		{
			q = p;
			while (q != NULL)
			{
				if (q->getDato() == '@')
				{
					arri = q;
					cout<<"encontrado"<<endl;
				}
				q = q->getSig();
			}
			p = p->getAbajo();
		}
	}
	else
		cout << "Lista vacia...";

	arri2 = arri->getArriba();

	if (arri2->getDato() == '0') {
		arri2->setDato(arri->getDato());
		arri->setDato('0');
		cout << "arriba" << endl;
	}
	cargaMapa(head);
	pantallaJuego->display();
}
