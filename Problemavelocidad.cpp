#include <stdio.h>

void pruebavelocidad(int *);

int main() {
	int fallos=0;
	pruebavelocidad(&fallos);
	pruebavelocidad(&fallos);
	printf("tus fallos totales han sido: %d", fallos);
	
}

void pruebavelocidad(int *fallos) {
	float anos = 0; int fallolocal=0;
	printf("Si la ecuacion de la velocidad es dx/dt,y la velocidad media de la nave es de 40.300 km/s,cuanto tiempo tardarás en años hasta Urano?\n");
	printf("Sabemos que el vector de posicion de urano con respecto a la nave espacial es (2850,-50) en millones de kilometros:\n");
	do {
		printf("introduce el numero de años: ");
		scanf_s("%f", &anos);
		if (anos <= 7.8 || 8.2 <= anos) {
			printf("\nDesgraciadamente sus calculos no son correctos. Vuleve a intentarlo.\n");
			fallolocal++;
			
		}
		else{
			printf("\nSus calculos son exactos, tardaremos aproximadamente %.2f años en llegar a Urano.\n",anos);
		}

	} while ((fallolocal < 3) && (anos <= 7.8||8.2 <= anos ));
	*fallos = *fallos + fallolocal;
	switch(fallolocal) {
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