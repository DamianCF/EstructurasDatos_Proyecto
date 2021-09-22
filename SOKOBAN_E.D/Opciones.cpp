#include "Opciones.h"

Opciones::Opciones(int ancho, int alto, string titu)
{
	ventana3 = new RenderWindow(VideoMode(ancho, alto),titu);
	background = new Texture;
	sprite1 = new Sprite;
	evento = new Event;

	background->loadFromFile("resource/bck4.jpg");
	sprite1->setTexture(*background);
	sprite1->setScale(((float)ventana3->getSize().x / sprite1->getTexture()->getSize().x), ((float)ventana3->getSize().y / sprite1->getTexture()->getSize().y));


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
	while (ventana3->isOpen())
	{
		ejecutar();


		dibujar();
	}
}

void Opciones::dibujar()
{
	ventana3->clear();
	ventana3->draw(*sprite1);
	ventana3->draw(*label);
	ventana3->display();
}

void Opciones::ejecutar()
{
	while (ventana3->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			ventana3->close();
			exit(1);
		}

	}
}

Opciones::~Opciones()
{
	
}