#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;
using namespace std;

class menu
{
public:
	menu(int resolucion_x, int resolucion_y, std::string titulo);
	void gameLoop();
	void cargar_graficos();
	void menu_inicio();

private:
	RenderWindow* ventana1;
	int fps;

	//pantalla de fondo
	Texture * letrasTxt;       //letras de menu de inicio
 	Sprite * letrasSpt;        //........................

	//seleccion de fondo
	Sprite spriteFondo[55];
	Texture texturaFondo[55];

	
	
	//nave de seleccion 
	Texture * texturaSelec;
	Sprite * spriteSelec;

	//relog para el tiempo
	Clock* reloj1;
	Time* tiempo1;
	int numero_textura = 0;
	int segundos = 1;
	int elejirEscena = 0;
};