#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<stdlib.h>
#include <string.h>

#define DIM 50

int prueba1(void);

typedef struct {
		char nombre[DIM];
		int puntuacion;
	}datos;

int main()
{	

	prueba1();
}





int prueba1(void) {
		int tamSS, * orden, i, fallos = 0, sol[8] = { 4,5,1,7,3,6,8,9 }, cont = 0, cont2 = 0;
		printf("Para acceder a los controles de la capsula deberas responder a lo siguiente:\nDi cuales de estos planetas pertenecen a nuestro sistema solar y ordenalos segun su posicion respecto al Sol.\n\n(**SI FALLAS 3 VECES LA CAPSULA PROCEDERA A BLOQUEARSE**)");
		do
		{
			//Aqui pablo deberia meter 10 imagenes de 10 planetas distintos: 8 del sistema solar 2 inventados (Si no es posible, se pueden presentar las opciones por escrito como lo voy a hacer a continuacion)
			printf("\nLas opciones son:\n\nT I E R R A \t(1)\n\nN A B O O \t(2)\n\nJ U P I T E R \t(3)\n\nM E R C U R I O \t(4)\n\nV E N U S \t(5)\n\nS A T U R N O \t(6)\n\nM A R T E \t(7)\n\nU R A N O \t(8)\n\nN E P T U N O \t(9)\n\nR´L Y E H \t(10)\n\nY bien, ¿Cuantos de estos planetas pertenecen a nuestro sistema?: ");
			scanf_s("%d", &tamSS);



			orden = (int*)malloc(tamSS * sizeof(int));
			if (orden == NULL)
				printf("Memoria insuficiente\n");
			else
			{
				printf("Respuesta guardada\n");
			}
			printf("Introduzca los numeros que representan a cada planeta en el orden que crea que les corresponda:\n");
			for (i = 0; i < tamSS; i++)
			{

				printf("Planeta %d: ", i + 1);
				scanf_s("%d", orden + i);//problema ya que se buggea si no metes un int
				cont++;
			}
			while (cont != 8)
			{
				fallos++;
				printf("**WARNING\tWARNING\tWARNING** HAS COMETIDO UN ERROR EN EL NUMERO DE LOS PLANETAS, PRUEBA OTRA VEZ: ");
				scanf_s("%d", &tamSS);
				for (i = 0; i < tamSS; i++)
				{
					cont2++;
					cont = cont2;
				}


			}
			cont = 0;
			for (i = 0; i < tamSS; i++)
			{
				if (*orden + 1 != sol[i])
				{
					cont++;
				}
			}
			while (cont != 0)
			{
				fallos++;
				cont2 = 0;
				printf("Has fallado el intento en las posiciones (has cometido %d errores en este intento pero no te preocupes, solo cuenta como que has fallado una vez el intento\n", cont);
				printf("prueba otra vez:\n ");
				for (i = 0; i < tamSS; i++)
				{
					printf("Planeta %d: ", i + 1);
					scanf_s("%d", orden + i);
					cont2++;
				}
				cont = cont2;
			}



			printf("Bien hecho, has pasado esta pregunta de seguridad");
			fallos = 3;




		} while (fallos != 3);
		return 0;
}
