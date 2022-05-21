#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

int main()
{
	int tamSS, *orden, i, fallos = 0, sol[8] = {4,5,1,7,3,6,8,9};
	int j, fallo2=0, k, h;
	char cad[30], sol2[30] = "Pedro Duque\0";
	printf("SPACESCAPE\n");
	printf("Al intentar encender los mandos de control de la c%cpsula, te das cuenta que el capit%cn de la nave espacial instal%c un sistema de reconocimiento.\n", 160, 160, 162);
	printf("Para asegurarse de que ning%cn extraterrestre est%c en posesi%cn de nuestra tecnolog%ca, primero debes introducir el n%cmero de planetas de nuestro sistema solar y su orden:\n", 163, 130, 162, 161, 163);
	printf("Las opciones son:\n\nT I E R R A \t(1)\n\nN A B O O \t(2)\n\nJ U P I T E R \t(3)\n\nM E R C U R I O (4)\n\nV E N U S \t(5)\n\nS A T U R N O \t(6)\n\nM A R T E \t(7)\n\nU R A N O \t(8)\n\nN E P T U N O \t(9)\n\nR %c LYEH \t(10)\n", 39);
	do
	{
		printf("Y bien, %cCuantos de estos planetas pertenecen a nuestro sistema?: \n", 168);
		scanf_s("%d", &tamSS);
		if (tamSS != 8)
		{
			fallos++;
			printf("%cEres de verdad un humano? Vuelve a intentarlo.\n", 168);

		}
	} while (tamSS != 8);
	do
	{
		orden = (int*)malloc(tamSS * sizeof(int));
		if (orden == NULL)
			printf("Memoria insuficiente\n");
		else
		{
			printf("Respuesta correcta\n");
		}
		orden = &sol[0];
		printf("Bien hecho, ahora introduzca los numeros que representan a cada planeta en el orden que les corresponda:\n");
		for (i = 0; i < tamSS; i++)
		{
			printf("Planeta %d: ", i + 1);
			scanf_s("%d", &orden[i]);
		}
			
	}while (orden != sol);
	printf("Bien hecho. Siguiente pregunta\n");
	do {
		printf("%cCu%cl es la presi%cn del interior de un traje espacial?\n", 168, 160, 162);
		printf("1.- 1 atm\n2.- 0.4 atm\n3.- 1.2 atm\n4.- 0.7 atm\n");
		scanf_s("%d", &j);
		if (j != 2)
		{
			printf("%cEres de verdad un astronauta? Vuelve a intentarlo.\n", 168);
			fallos++;
		}
	}while(j != 2);
	printf("Buen camino, sigue as%c. %cltima pregunta.\n", 161, 163);
	do
	{
		printf("%cQui%cn fue el primer astronauta espa%col\n", 168,130,164);
		getchar();
		gets_s(cad);
		cad[12] = '\0';
		k = strcmp(cad, sol2);
		if (k != 0)
		{
			fallos++;
			printf("%cSeguro que eres miembro de la tripulaci%cn de esta nave espa%cola?\nNo te olvides de las may%csculas\n", 168, 162, 164, 163);
		}
	} while (k!=0);
	printf("Definitivamente eres miembro de esta tripulaci%cn. Enhorabuena, has conseguido el control de los mandos.\n", 162);

}
