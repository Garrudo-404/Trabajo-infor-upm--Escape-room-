#include <stdio.h>
#define DIM 2

int main()
{
	int V1[] = { 150, 50 }, V2[] = { 3000,0 }, Vsol[DIM], Vresp[DIM];
	int i, j, cont = 0;
	printf("La c%cpsula necesita que le indiques el vector direcci%cn que debe seguir en su trayectoria. Urano se halla a 3000M de kil%cmetros de %cl, si la nave se encuentra a 50M de  kil%cmetros por encima de la Tierra que est%c a 150M de  kil%cmetros, ¿Cu%cl es el vector direcci%cn que la nave debe seguir? ", 160, 162, 162, 130, 162, 160, 162, 160, 162);
	for (i = 0; i < DIM; i++)
	{
		Vsol[i] = V2[i] - V1[i];
	}
	i = 0;
	while (i < DIM) {
		printf("Introduce el vector:\n");
		for (j = 0; j < DIM; j++) {
			scanf_s("%d", &Vresp[j]);
		}
		for (j = 0; j < DIM; j++) {
			if (Vsol[j] == Vresp[j]) {
				i++;
			}
			else {
				printf("Vuelve a intentarlo\n");
				cont++;
				break;
			}
		}

	}
	printf("Enhorabuena has pasado la prueba\n");
}