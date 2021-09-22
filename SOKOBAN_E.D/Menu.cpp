#include "Menu.h"

Menu::Menu(int ancho, int alto, string titulo)
{
	fps = 60;

	ventana1 = new RenderWindow(VideoMode(ancho, alto), titulo);

	ventana1->setFramerateLimit(fps);

	background = new Texture;
	sprite1 = new Sprite;

	background->loadFromFile("resource/bck2.jpg");

	sprite1->setTexture(*background);
	//sprite1->setScale(400.f/sprite1->getTexture()->getSize().x,400.f/sprite1->getTexture()->getSize().y);//dimension deseada dividido tamano actual
	sprite1->setScale(((float)ventana1->getSize().x / sprite1->getTexture()->getSize().x),((float) ventana1->getSize().y / sprite1->getTexture()->getSize().y));
	//IntRect posicion(128,384,128,128);
	//sprite1->setTextureRect(posicion);

	fuente = new Font();
	fuente->loadFromFile("fonts/PressStart2P-Regular.ttf");

	/*label1 = new Text();
	label2 = new Text();
	label3 = new Text();
	label4 = new Text();

	label1->setFont(*fuente);
	label2->setFont(*fuente);
	label3->setFont(*fuente);
	label4->setFont(*fuente);

	label1->setFillColor(Color::White);
	label2->setFillColor(Color::White);
	label3->setFillColor(Color::White);
	label4->setFillColor(Color::White);

	label1->setString("PLAY");
	label2->setString("OPCIONES");
	label3->setString("ACERCA DE");
	label4->setString("EXIT");

	label1->setCharacterSize(40);
	label2->setCharacterSize(40);
	label3->setCharacterSize(40);
	label4->setCharacterSize(40);

	label1->setPosition(300,100);
	label2->setPosition(300, 150);
	label3->setPosition(300, 200);
	label4->setPosition(300, 250);*/

	pv[0].setFont(*fuente);
	pv[0].setString("PLAY");
	pv[0].setFillColor(Color::Blue);
	pv[0].setPosition(300, 100);
	pv[0].setCharacterSize(40);

	pv[1].setFont(*fuente);
	pv[1].setString("OPCIONES");
	pv[1].setFillColor(Color::White);
	pv[1].setPosition(300, 150);
	pv[1].setCharacterSize(40);

	pv[2].setFont(*fuente);
	pv[2].setString("ACERCA DE");
	pv[2].setFillColor(Color::White);
	pv[2].setPosition(300, 200);
	pv[2].setCharacterSize(40);

	pv[3].setFont(*fuente);
	pv[3].setString("EXIT");
	pv[3].setFillColor(Color::White);
	pv[3].setPosition(300, 250);
	pv[3].setCharacterSize(40);

	MenuSeleccionado = 0;

	evento1 = new Event;
	gameloop();

}

void Menu:: gameloop()
{
	while (ventana1->isOpen())
	{
		ejecutar_eventos();
		

		dibujar();
	}
}

void Menu::dibujar()
{
	ventana1->clear();
	ventana1->draw(*sprite1);
	//ventana1->draw(*label1);
	//ventana1->draw(*label2);
	//ventana1->draw(*label3);
	//ventana1->draw(*label4);
		for (int i = 0;i < Max_menu; i++)
	{
		ventana1->draw(pv[i]);
	}

	ventana1->display();
}



void Menu::ejecutar_eventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		if (evento1->type == Event::Closed)
		{
			ventana1->close();
			exit(1);
		}
		if (evento1->type == Event::KeyReleased)
		{
			if (evento1->key.code == Keyboard::Up)
			{
				MoverArriba();
				break;
			}
			if (evento1->key.code == Keyboard::Down)
			{
				Moverabajo();
				break;
			}
			if (evento1->key.code == Keyboard::Return)
			{
				
				

				int x = MenuPressed();
				if (x == 0)
				{
					game = new Juego(960, 540, "SOKOBAN");
				}
				if (x == 1)
				{
					options = new Opciones(960, 540, "SOKOBAN");
				}
			}
		}
		/*	switch (evento1->type)
			{
			case Event::Closed:
				ventana1->close();
				exit(1);
				break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					exit(1);
				}
			}
		}*/
	}
}

void Menu::MoverArriba()
{
	if (MenuSeleccionado - 1 >= 0)
	{
		pv[MenuSeleccionado].setFillColor(Color::White);

		MenuSeleccionado--;
		if (MenuSeleccionado == -1)
		{
			MenuSeleccionado = 2;
		}
		pv[MenuSeleccionado].setFillColor(Color::Blue);
	}
}

void Menu::Moverabajo()
{
	if (MenuSeleccionado + 1 <= Max_menu)
	{
		pv[MenuSeleccionado].setFillColor(Color::White);
		MenuSeleccionado++;
		if (MenuSeleccionado == Max_menu)
		{
			MenuSeleccionado = 0;
		}
		pv[MenuSeleccionado].setFillColor(Color::Blue);
	}
}

Menu::~Menu()
{

}