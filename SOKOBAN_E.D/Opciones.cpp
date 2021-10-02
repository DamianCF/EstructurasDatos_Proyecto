#include "Opciones.h"
#include "Menu.h"

Opciones::Opciones(int ancho, int alto, string titu)
{
	menuOpciones = new RenderWindow(VideoMode(ancho, alto),titu);
	texturaFondo = new Texture;
	basePantalla = new Sprite;
	evento = new Event;

	texturaFondo->loadFromFile("resource/fondoOpciones.jpg");
	basePantalla->setTexture(*texturaFondo);
	basePantalla->setScale(((float)menuOpciones->getSize().x / basePantalla->getTexture()->getSize().x), ((float)menuOpciones->getSize().y / basePantalla->getTexture()->getSize().y));


	fuente = new Font();
	fuente->loadFromFile("fonts/PressStart2P-Regular.ttf");

	label = new Text();
	label->setFont(*fuente);
	label->setFillColor(Color::White);
	label->setString("OPCIONES...");
	label->setCharacterSize(40);
	label->setPosition(300, 100);
	gameloop();
}

void Opciones::gameloop()
{
	while (menuOpciones->isOpen())
	{
		ejecutar();


		dibujar();
	}
}

void Opciones::dibujar()
{
	menuOpciones->clear();
	menuOpciones->draw(*basePantalla);
	menuOpciones->draw(*label);
	menuOpciones->display();
}

void Opciones::ejecutar()
{
	while (menuOpciones->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			menuOpciones->close();
			exit(1);
		}

		if (evento->key.code == Keyboard::Escape)// tecla presionada fue la tecla "ENTER"
		{
			Menu* devolver;
			menuOpciones->close();
			devolver = new Menu(960, 540, "SOKOBAN");
		}

	}
}

Opciones::~Opciones()
{
	
}