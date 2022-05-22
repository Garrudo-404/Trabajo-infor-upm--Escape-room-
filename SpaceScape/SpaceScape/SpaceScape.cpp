#include<stdlib.h>
#include <ctime>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#define DIM 50

void prueba1(void);
void prueba2(void);
int prueba7(void);
void pruebavelocidad(int*);
int prueba4(int*, int*);
void prueba5(void);
int fimg(char*, int, int);

int main()
{
	//Prueba 1
	prueba1();
	//Prueba 2
	printf("\n");
	prueba2();
	// Prueba 3
	//Prueba 4
	int situacion = 200, puntuacion = 0;
	prueba4(&situacion, &puntuacion);
	printf("su puntuacion final es: %d %d", puntuacion, situacion);
	
	//Prueba 6
	int fallos = 0;
	pruebavelocidad(&fallos);
	pruebavelocidad(&fallos);
	printf("tus fallos totales han sido: %d", fallos);
	//Prueba 7
	prueba7();
}
int prueba7()
{//codigo morse
	int intentos = 3, test; char morse[DIM];
	printf("escribe SOS en codigo morse utilizando '.' y '_':\n");
	while ((strcmp(morse, "...___...")) && (intentos >= 1)) {//hasta que sea correcto
		gets_s(morse);
		if (abs(strcmp(morse, "...___...")) && (intentos >= 1)) {

			switch (intentos) {
			case 3:
				printf("\nEl codigo es incorrecto, la senal sera inhibida.\nVuelve a intentarlo, te quedan 2 intentos:\n");
				intentos--;
				break;
			case 2:
				printf("\nEl codigo es incorrecto, la senal sera inhibida.\nVuelve a intentarlo, te quedan 1 intento:\n");
				intentos--;
				break;
			case 1:
				printf("\nEl codigo es incorrecto, la senal sera inhibida.\n");
				intentos--;
				break;
			}
		}
	}
	switch (intentos) {
	case 3:
		printf("La senal ha sido enviada correctamente!! Lo has logrado al primer intento\n");
		break;
	case 2:
		printf("La senal ha sido enviada correctamente!! Lo has lo grado al segundo intento\n");
		break;
	case 1:
		printf("La senal ha sido enviada correctamente!! Lo has logrado al ultimo intento\n");
		break;
	case 0:
		printf("Desgraciadamente no has logrado enviar la senal de socorro...\n");
		break;
	}

	return 0;
}
void prueba1()
{
	int tamSS, * orden, i=0, fallos = 0, sol[8] = { 4,5,1,7,3,6,8,9 };
	int j, fallo2 = 0, k, h;
	char cad[30], sol2[30] = "Pedro Duque";
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
		orden = (int*)malloc(tamSS * sizeof(int));
		if (orden == NULL)
			printf("Memoria insuficiente\n");
		else
		{
			printf("Respuesta correcta\n");
		}
		printf("Bien hecho, ahora introduzca los numeros que representan a cada planeta en el orden que les corresponda:\n");
		while (i < tamSS)
		{
			printf("Planeta %d: ", i + 1);
			scanf_s("%d", &orden[i]);
			if (sol[i] == orden[i])
				i++;
			else
				printf("Incorrecto,vuelve a intentarlo\n");
		}
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
	} while (j != 2);
	printf("Buen camino, sigue as%c. %cltima pregunta.\n", 161, 163);
	do
	{
		printf("%cQui%cn fue el primer astronauta espa%col\n", 168, 130, 164);
		getchar();
		gets_s(cad);
		cad[12] = '\0';
		k = strcmp(cad, sol2);
		if (k != 0)
		{
			fallos++;
			printf("%cSeguro que eres miembro de la tripulaci%cn de esta nave espa%cola?\nNo te olvides de las may%csculas\n", 168, 162, 164, 163);
		}
	} while (k != 0);
	printf("Definitivamente eres miembro de esta tripulaci%cn. Enhorabuena, has conseguido el control de los mandos.\n", 162);
}
void pruebavelocidad(int* fallos)
{
	float anos = 0; int fallolocal = 0;
	printf("Si la ecuacion de la velocidad es dx/dt,y la velocidad media de la nave es de 40.300 km/s,cuanto tiempo tardarás en años hasta Urano?\n");
	printf("Sabemos que el vector de posicion de urano con respecto a la nave espacial es (2850,-50) en millones de kilometros:\n");
	do {
		printf("introduce el numero de años: ");
		scanf_s("%f", &anos);
		if (anos <= 7.8 || 8.2 <= anos) {
			printf("\nDesgraciadamente sus calculos no son correctos. Vuleve a intentarlo.\n");
			fallolocal++;

		}
		else {
			printf("\nSus calculos son exactos, tardaremos aproximadamente %.2f años en llegar a Urano.\n", anos);
		}

	} while ((fallolocal < 3) && (anos <= 7.8 || 8.2 <= anos));
	*fallos = *fallos + fallolocal;
	switch (fallolocal) {
	case 0:
		printf("excelente no has cometido ningun fallo!\n");
		break;
	case 1:
		printf("solo has cometido un fallo.\n");
		break;
	case 2:
		printf("has cometido 2 fallos, deberias mejorar.\n");
		break;
	case 3:
		printf("menudo cateto, has suspendido.\n");
		break;
	}
}
int prueba4(int* situacion, int* puntuacion)
{
	char d1, respU[DIM], respC[] = { "urano" };

	int bonus = 100, proof = 1;//variables locales

	do {  //usuario debe decidir
		printf("El sistema de refrigeracion de los motores principales está fallando!\nDebe introducir la contraseña del sistema. Desea hacerlo? S/N: ");
		scanf_s("%c", &d1);
		if (not((d1 == 's') || (d1 == 'n'))) {
			printf("\nno entiendo su respuesta...\n");
		}
	} while (not((d1 == 's') || (d1 == 'n')));


	switch (d1) {  //posibles sucesos

	case 's':


		do {
			printf("La contrasena es la respuesta al siguiente acertijo, pero ten cuidado cuanto mas falles menor puntuacion obtendras:\nEl planeta mas frio del sistema solar y con 27 lunas lo verás girar\n");
			gets_s(respU);
			if (strcmp(respU, respC) == 0) {
				printf("\nEnorabuena has resuelto el acertijo\n");
				proof = 0;
			}
			else {
				printf("\nesa no era la respuesta correcta, vuelve a intentarlo\n");
				if (bonus > 20) {
					bonus = bonus - 20;
				}
			}
		} while (proof);
		*situacion = *situacion + 100;
		*puntuacion = *puntuacion + bonus;
		break;


	case 'n':
		printf("todos nuestros actos tienen consecuencias\n");
		*situacion = *situacion - 100;

		break;
	}

	return 0;
}
void prueba5(void) {
	//Prueba 5
	int Vt[DIM], Vu[DIM], Vresp[DIM];
	int Vsol[] = { 2850, -50 };
	int i, j, cont = 0;
	printf("La c%cpsula necesita que le indiques el vector direcci%cn que debe seguir en su trayectoria. Urano se halla a 3000M de kil%cmetros de %cl, si la nave se encuentra a 50M de  kil%cmetros por encima de la Tierra que est%c a 150M de  kil%cmetros, ¿Cu%cl es el vector direcci%cn que la nave debe seguir? ", 160, 162, 162, 130, 162, 160, 162, 160, 162);

	printf("\n\nV1: ");
	for (i = 0; i < DIM; i++)
	{
		scanf_s("%d", &Vt[i]);
	}
	printf("\n\nV2: ");
	for (i = 0; i < DIM; i++)
	{
		scanf_s("%d", &Vu[i]);
	}
	for (i = 0; i < DIM; i++)
	{
		Vresp[i] = Vu[i] - Vt[i];
	}
	for (i = 0; i < DIM; i++)
	{
		if (Vresp[i] != Vsol[i])
		{
			while (Vresp[i] != Vsol[i])
			{
				printf("\nRevisa los c%clculos.", 133);
				printf("\n\nV1: ");
				for (i = 0; i < DIM; i++)
				{
					scanf_s("%d", &Vt[i]);
				}
				printf("\n\nV2: ");
				for (i = 0; i < DIM; i++)
				{
					scanf_s("%d", &Vu[i]);
				}
				for (i = 0; i < DIM; i++)
				{
					Vresp[i] = Vu[i] - Vt[i];
				}
			}
		}
		if (Vresp[i] == Vsol[i])
		{
			cont++;
		}

	}
	if (cont == 2)
	{
		printf("\nDirecci%cn correctamente introducida", 162);
	}
}
void prueba2(void) {
	printf("Para poder encender los motores de la cápsula, tienes que introducir una clave de 9 dígitos.Sabes que la");
	printf("clave solo la sabía el capitán, por eso intentas recordar sus pertenencias");
	printf("personales para ver si encuentras alguna pista. Encuentras su libro preferido, una fotografía y su reloj.");
	int clave[9] = { 2,6,6,0,3,6,2,9,7 }, i = 0, tamv1, tamv2, sol;//1984+2330+26031983=266036297.
	char img1[] = "images/1984.jpg", img2[] = "images/foto con fecha.jpeg", img3[] = "images/reloj.jpg";
	tamv1 = 800, tamv2 = 700;
	fimg(img1, tamv1, tamv2);
	fimg(img2, tamv1, tamv2);
	fimg(img3, tamv1, tamv2);
	printf("Escribe la clave:");
	while (i < 9) {
		scanf_s("%d", &sol);
		if (sol == clave[i])
			i++;
		else
			printf("Incorrecto,vuelve a intentarlo\n");
	}
	printf("Enhorabuena, has pasado la prueba\n");
}
int fimg(char* im, int tam1, int tam2) {
	sf::RenderWindow window{ sf::VideoMode(tam1,tam2), "Escaperoom" };
	sf::Texture t;
	t.loadFromFile(im);
	sf::Sprite s(t);
	while (window.isOpen())
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		window.draw(s);
		window.display();
	}
	return 0;
}
