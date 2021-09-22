#include "Juego.h"
#include "Menu.h"

Juego::Juego(int ancho, int alto, string titu)
{
	ventana2 = new RenderWindow(VideoMode(ancho,alto),titu);
	background = new Texture;
	sprite1 = new Sprite;
	evento = new Event;

	background->loadFromFile("resource/bck3.jpg");
	sprite1->setTexture(*background);
	sprite1->setScale(((float)ventana2->getSize().x / sprite1->getTexture()->getSize().x), ((float)ventana2->getSize().y / sprite1->getTexture()->getSize().y));
	

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
	while (ventana2->isOpen())
	{
		ejecutar();


		dibujar();
	}
}

void Juego::dibujar()
{
	ventana2->clear();
	ventana2->draw(*sprite1);
	ventana2->draw(*label1);
	ventana2->display();
}

void Juego::ejecutar()
{
	while (ventana2->pollEvent(*evento))
	{
		if (evento->type == Event::Closed)
		{
			ventana2->close();
			exit(1);
		}
		if (evento->type == Event::KeyReleased)
		{
			if (evento->key.code == Keyboard::Escape)
			{
				Menu* backmain;
				backmain = new Menu (960, 540, "SOKOBAN");
			}
		}
	}
}

void Juego::crearGrid()
{

}
Juego::~Juego()
{

}