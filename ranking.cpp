#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<malloc.h>
#define DIM 50

typedef struct {//asignar memoria "estandar"
	int puntuacion;
	char nombre[DIM];
}jugador;


void introducirnombre(jugador*);
void recogerRanking_fichero(jugador j[]);//copia los nombres y puntuaciones de jugadores a una lista
int conteolista(void);//determina la cantidad de entradas del ranking
void ordenarRanking(jugador j[],jugador );





int main() {
	//primero leer un fichero y guardar en una cadena sus datos
	int n = conteolista();
	jugador* j1;

	j1 = (jugador*)malloc((n + 1) * sizeof(int)); //malloc dimension de la lista
	if (j1 == NULL) {
		printf("memoria insuficiente");
	}
	else {
		recogerRanking_fichero(j1);
		printf("hello world\n");
	}



	//juego

	jugador main;//datos de la partida
	introducirnombre(&main);




	
	printf("introduce tu puntuacion final: ");
	scanf_s("%d", &main.puntuacion);




	if (j1 == NULL) {
		printf("sin memoria");
	}
	else {
		ordenarRanking(j1, main);
	}
}
void introducirnombre(jugador *main) {
	printf("Para empezar a jugar introduce tu nickname: ");
	gets_s(main->nombre);
}

void recogerRanking_fichero(jugador j1[]) {
		int i = 0;

		FILE* f1;
		f1 = fopen("ranking.txt", "r");

		while (feof(f1) == 0)//lectura
		{
			fscanf(f1, "%s %d", j1[i].nombre,&j1[i].puntuacion);
			i++;
		}
		fclose(f1);
	}

int conteolista(void) { 
	int n=0,puntuacion;
	char nombre[DIM];
	FILE* f1;
	f1 = fopen("ranking.txt", "r");
	while(feof(f1) == 0)//lectura
	{
		fscanf(f1, "%s %d", nombre, &puntuacion);
		n++;
	}
	fclose(f1);
	return n;
}

void ordenarRanking(jugador j1[], jugador main) {
	int n = conteolista(),p;
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
		while (i<=n)//sobreescritura
		{
			fprintf(f1, "%s %d", j2[i].nombre, j2[i].puntuacion);
			i++;
		}
		fclose(f1);
	}
}



