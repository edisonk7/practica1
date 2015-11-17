#include <conio.h>
#include <stdio.h>
#include <windows.h>

void pintar(int ancho, int posX, int posB1, int posB2) 
{
	int i = 0;
	printf("\r");
	while (i <= ancho)
	{
		if (i == posX)
			printf("X");
		else if(i == posB1 && posB1 !=-1)
			printf("<");
		else if (i == posB2 && posB2 != -1)
			printf(">");
		else
			printf("=");
		++i;
	}
	Sleep(25);
}

int main()
{
	bool jugar = 1;
	int posX = 39;
	int ancho = 78;
	int posB1=-1;
	int posB2=-1;
	int tecla=0;
	const int o = 111;
	const int p = 112;
	const int q = 113;
	const int r = 114;
	const int ESC = 27;

	printf("\n\n\n\n\n\n\t\t\t Practica 1 : \n\n o:Izquierda, p:derecha, q:bala derecha, r:bala izquierda, ESC: Salir \n\n\n\n\n\n");
	while (jugar)
	{
		if (_kbhit() != 0)
		{
			tecla = _getch();
			if (tecla == p && posX<ancho)
				++posX;
			else if (tecla == o && posX>0)
				--posX;
			else if (tecla == q)
				posB1 = posX-1;
			else if (tecla == r)
				posB2 = posX+1;
			else if (tecla == ESC)
				jugar = 0;
		}
		pintar(ancho, posX, posB1, posB2);

		if (posB1 == 0)
			posB1 = -1;
		else if(posB1 != -1)
			--posB1;
		if (posB2 == ancho)
			posB2 = -1;
		else if(posB2 != -1)
			++posB2;
	}
	return(0);
}