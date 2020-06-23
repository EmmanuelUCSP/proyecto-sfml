#include "menu.h"

//crear la ventana
menu::menu(int resolucion_x, int resolucion_y, std::string titulo)
{
	fps = 60;
	ventana1 = new RenderWindow(VideoMode(resolucion_x, resolucion_y), "titulo");
	ventana1->setFramerateLimit(fps);
	reloj1 = new Clock();
	tiempo1 = new Time();


	//letras de menu de inicio
	letrasTxt = new Texture;
	letrasSpt = new Sprite;
	letrasTxt->loadFromFile("img/fondo/letras.png");
	letrasSpt->setTexture(*letrasTxt);

	//nave de seleccion
	texturaSelec = new Texture;
	texturaSelec->loadFromFile("img/naveSeleccion.png");
	spriteSelec = new Sprite(*texturaSelec);
	//colocar la nave
	spriteSelec->setPosition(230,430);          
	//reduccion de la nave de seleccion
    spriteSelec->setScale(100.f / spriteSelec->getTexture()->getSize().x, 100.f / spriteSelec->getTexture()->getSize().y);
	
	cargar_graficos();  //graficos del fondo
	gameLoop();
}

void menu::menu_inicio()
{
	if (tiempo1->asSeconds() > 0.05)  //controla la velocidad de la animación
	{
		numero_textura += 1;
		reloj1->restart();
		if (numero_textura == 55)
			numero_textura = 0;
	}
	ventana1->draw(spriteFondo[numero_textura]);

	ventana1->draw(*spriteSelec);        //nave de seleccion
	ventana1->draw(*letrasSpt);         //letras de seleccion

}


void menu::gameLoop()
{
	
	while (ventana1->isOpen())
	{
		////////////////////////////////////////////
		ventana1->clear();
		*tiempo1 = reloj1->getElapsedTime();
		cout << tiempo1->asSeconds() << endl;
		
		if(elejirEscena==0)
			menu_inicio();



		ventana1->display();
		
		
	}
}

void menu::cargar_graficos()
{
	string path;
	for (int i = 0; i < 55; i++)
	{
		path = "img/fondo/fondo_" + to_string(i) + ".jpg";
		texturaFondo[i].loadFromFile(path);
		spriteFondo[i].setTexture(texturaFondo[i]);
	}
}


