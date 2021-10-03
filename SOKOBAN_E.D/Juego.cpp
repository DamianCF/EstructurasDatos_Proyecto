#include "Juego.h"
#include "Menu.h"

Juego::~Juego()
{
}

Juego::Juego(int ancho, int alto, string titu)
{
	pantallaJuego = new RenderWindow(VideoMode(ancho,alto),titu);
	background = new Texture;
	sprite1 = new Sprite;

	/*
	Tmuros = new Texture;
	Tmuros->loadFromFile("resource/1.png");
	IntRect posicion(1408,768 , 128, 128);
	Smuro = new Sprite;
	Smuro2 = new Sprite;
	Smuro->setTextureRect(posicion);
	Smuro->setTexture(*Tmuros);*/
	//Smuro->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);
	//Smuro->setPosition(580, 200);

	Smuro2->setTextureRect(posicion);
	Smuro2->setTexture(*Tmuros);
	Smuro2->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);
	Smuro2->setPosition(620, 200);
	

	evento = new Event;

	background->loadFromFile("resource/fondoLadrillos.jpg");
	sprite1->setTexture(*background);
	sprite1->setScale(((float)pantallaJuego->getSize().x / sprite1->getTexture()->getSize().x), ((float)pantallaJuego->getSize().y / sprite1->getTexture()->getSize().y));
	

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
				backmain = new Menu (960, 540, "SOKOBAN");
			}
		}
	}
}

void Juego::crearGrid()
{
	pantallaJuego->clear();
	pantallaJuego->draw(*sprite1);
	//pantallaJuego->draw(*label1);

	obj = new ListaOrtogonal();
	obj->cargarNivel("Mapas/Nivel1.txt");
	obj->cargarLista(9, 9, head);
	cargaMapa(head);
	pantallaJuego->display();
}

void Juego::cargaImagen(char caracter, int x ,int y) {
	Texture* Tmuros = new Texture();
	Sprite* Smuro = new Sprite;

		Tmuros->loadFromFile("resource/1.png");
		IntRect posicion(1408, 768, 128, 128);

		Smuro->setTextureRect(posicion);
		Smuro->setTexture(*Tmuros);
		Smuro->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);
		Smuro->setPosition(x,y);
		pantallaJuego->draw(*Smuro);
	

	//# paredes
	if (caracter == '#') {
		//Tmuros->loadFromFile("resource/1.png");
		IntRect posicion(1152, 768, 128, 128);

		Smuro->setTextureRect(posicion);
		//Smuro->setTexture(*Tmuros);
		//Smuro->setScale(800.f / Smuro->getTexture()->getSize().x, 400.f / Smuro->getTexture()->getSize().y);
		Smuro->setPosition(x, y);
		pantallaJuego->draw(*Smuro);
	}

	//$ cajas
	if (caracter == '$') {
		IntRect posicion(128, 256, 128, 128);
		Smuro->setTextureRect(posicion);
		Smuro->setPosition(x, y);
		pantallaJuego->draw(*Smuro);
	}

	//. metas
	if (caracter == '.') {
		IntRect posicion(1408, 896, 128, 128);
		Smuro->setTextureRect(posicion);
		Smuro->setPosition(x, y);
		pantallaJuego->draw(*Smuro);
	}

	//@ personaje
	if (caracter == '@') {
		IntRect posicion(0, 640, 128, 128);
		Smuro->setTextureRect(posicion);
		Smuro->setPosition(x, y);
		pantallaJuego->draw(*Smuro);
	}
}

void Juego::cargaMapa(Nodo* head) {
	Nodo* aux1 = NULL, * aux2 = NULL;

	int x = 200;
	int y = 50;
	if (head != NULL)
	{
		aux1 = head;
		while (aux1 != NULL)
		{
			aux2 = aux1;
			while (aux2 != NULL)
			{
				cargaImagen(aux2->getDato(),x,y);
				aux2 = aux2->getSig();
				x = x+62;
			}
			x = 200;
			aux1 = aux1->getAbajo();
			y = y+50;
		}
	}
	else
		cout << "Lista vacia...";
}
