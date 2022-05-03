//he incluido variables random que se pueden quitar como puntuacion y situacion, situacion se puede usar para dejar menos intentos si hay muchos fallos

#include <stdio.h>
#include <string.h>
#define DIM 50

int prueba1(int *,int *);

int main() {
	int situacion = 200,puntuacion=0;

	prueba1(&situacion,&puntuacion);
	printf("su puntuacion final es: %d %d",puntuacion,situacion);
}

int prueba1(int *situacion,int *puntuacion) {
	char d1, respU[DIM], respC[] = { "urano" };

	int bonus=100,proof=1;//variables locales

	do {  //usuario debe decidir
		printf("El sistema de refrigeracion de los motores principales está fallando!\nDebe introducir la contraseña del sistema. Desea hacerlo? S/N: ");
		scanf_s("%c", &d1);
		if (not((d1 == 's') || (d1 == 'n'))) {
			printf("\nno entiendo su respuesta...\n");
		}
	} while (not((d1 =='s') || (d1 =='n')));


	switch (d1){  //posibles sucesos

	case 's':
	
	
	do{
		printf("La contrasena es la respuesta al siguiente acertijo, pero ten cuidado cuanto mas falles menor puntuacion obtendras:\nEl planeta mas frio del sistema solar y con 27 lunas lo verás girar\n");
		gets_s(respU);
		if (strcmp(respU, respC) == 0) {
			printf("\nEnorabuena has resultp el acertijo\n");
			proof = 0;
		}
		else {
			printf("\nesa no era la respuesta correcta, vuelve a intentarlo\n");
			if (bonus > 20) {
				bonus = bonus - 20;
			}
		}
	} while (proof);
	*situacion = *situacion+100;
	*puntuacion = *puntuacion + bonus;
	break;


	case 'n':
	printf("todos nuestros actos tienen consecuencias\n");
	*situacion = *situacion-100;
	
	break;
	}
	
	return 0;
}