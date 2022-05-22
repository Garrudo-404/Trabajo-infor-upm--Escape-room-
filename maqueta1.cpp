#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <malloc.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#define DIM 50
typedef struct {
	int puntuacion;
	char nombre[DIM];
}jugador;


//funciones asociadas al ranking
void introducirnombre(jugador*);
void recogerRanking_fichero(jugador j[]);//copia los nombres y puntuaciones de jugadores a una lista
int conteolista(void);//determina la cantidad de entradas del ranking
void ordenarRanking(jugador j[], jugador);



//funciones asociadas a las pruebas del juego
void prueba1(int*);
void prueba2(int*);
void prueba4( int*);
void prueba5(int*);
void prueba6(int*);
void prueba7(int*);

int fimg(char*, int, int);

int main()
{
	//primero leer un fichero y guardar en una cadena sus datos
	int n = conteolista();
	jugador* j1;

	j1 = (jugador*)malloc((n + 1) * sizeof(int)); //malloc dimension de la lista
	if (j1 == NULL) {
		printf("memoria insuficiente");
	}
	else {
		recogerRanking_fichero(j1);
	}

	//declaracion de jugador
	jugador main;
	introducirnombre(&main);


	//desarrollo del juego
	main.puntuacion = 0;
	prueba1(&main.puntuacion);
	prueba2(&main.puntuacion);
	prueba4(&main.puntuacion);
	prueba5(&main.puntuacion);
	prueba6(&main.puntuacion);
	prueba7(&main.puntuacion);
	

	//guardar datos del jugados en un fichero
	if (j1 == NULL) {
		printf("sin memoria");
	}
	else {
		ordenarRanking(j1, main);
	}

}


//funciones asociadas al ranking
void introducirnombre(jugador* main) {
	printf("Para empezar a jugar introduce tu nickname: ");
	gets_s(main->nombre);
}
void recogerRanking_fichero(jugador j1[]) {
	int i = 0;

	FILE* f1;
	f1 = fopen("ranking.txt", "r");

	while (feof(f1) == 0)//lectura
	{
		fscanf(f1, "%s %d", j1[i].nombre, &j1[i].puntuacion);
		i++;
	}
	fclose(f1);
}
int conteolista(void) {
	int n = 0, puntuacion;
	char nombre[DIM];
	FILE* f1;
	f1 = fopen("ranking.txt", "r");
	while (feof(f1) == 0)//lectura
	{
		fscanf(f1, "%s %d", nombre, &puntuacion);
		n++;
	}
	fclose(f1);
	return n;
}
void ordenarRanking(jugador j1[], jugador main) {
	int n = conteolista(), p;
	jugador* j2;//creamos una segunda lista para reordenar los terminos en puntuacion decreciente

	j2 = (jugador*)malloc((n + 1) * sizeof(int)); //malloc dimension de la lista
	if (j2 == NULL) {
		printf("memoria insuficiente");
	}
	else {
		j1[n].puntuacion = main.puntuacion;
		strcpy(j1[n].nombre, main.nombre);
		for (int i = 0; i <= n; i++) {//algoritmo para ordenar j2 de mayor a menor puntuacion
			j2[i].puntuacion = 0;

			for (int j = 0; j <= n; j++) {

				if (j1[j].puntuacion > j2[i].puntuacion) {
					j2[i].puntuacion = j1[j].puntuacion;
					strcpy(j2[i].nombre, j1[j].nombre);
					p = j;
				}

			}
			j1[p].puntuacion = -1;


		}
		for (int i = 0; i <= n; i++) {//imprime el ranking
			printf("j2 %s : %d\n", j2[i].nombre, j2[i].puntuacion);
		}

		FILE* f1; int i = 0;
		f1 = fopen("ranking.txt", "w");
		while (i <= n)//sobreescritura
		{
			fprintf(f1, "%s %d", j2[i].nombre, j2[i].puntuacion);
			i++;
		}
		fclose(f1);
	}
}

//funciones asociadas a las pruebas del juego
void prueba1(int* puntuacion)
{
	int tamSS, * orden, i = 0, fallos = 0, sol[8] = { 4,5,1,7,3,6,8,9 };
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
	*puntuacion = *puntuacion + (1000 - fallos * 100);
}
void prueba2(int* puntuacion) {
	int fallos = 0;
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
	while ((i < 9) && fallos<=3) {
		scanf_s("%d", &sol);
		if (sol == clave[i])
			i++;
		else
			printf("Incorrecto,vuelve a intentarlo\n");
		fallos++;
	}
	printf("Enhorabuena, has pasado la prueba\n");
	*puntuacion = *puntuacion + (300 - fallos * 100);
}
void prueba4( int* puntuacion)
{
	char d1, respU[DIM], respC[] = { "urano" }; int fallos = 0;

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
				fallos++;
			}
		} while (proof&&fallos<=3);
		break;


	case 'n':
		printf("todos nuestros actos tienen consecuencias\n");
		fallos = 3;

		break;
	}
	*puntuacion = *puntuacion + (300 - fallos * 100);
}
void prueba5(int* puntuacion) {
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
void prueba6(int* puntuacion)
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
	switch (fallolocal) {
	case 0:
		*puntuacion = *puntuacion + 300;
		break;
	case 1:
		*puntuacion = *puntuacion + 200;
		break;
	case 2:
		*puntuacion = *puntuacion + 100;
		break;
	case 3:
		break;
	}
}
void prueba7(int* puntuacion)
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
		*puntuacion = *puntuacion + 300;

		break;
	case 2:
		printf("La senal ha sido enviada correctamente!! Lo has lo grado al segundo intento\n");
		*puntuacion = *puntuacion + 200;
		break;
	case 1:
		printf("La senal ha sido enviada correctamente!! Lo has logrado al ultimo intento\n");
		*puntuacion = *puntuacion + 100;
		break;
	case 0:
		printf("Desgraciadamente no has logrado enviar la senal de socorro...\n");
		break;
	}
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