#include <stdio.h>
#define DIM 2

int main()
{
	int Vt[DIM], Vu[DIM], Vresp[DIM];
	int Vsol[] = { 2850, -50 };
	int i,j, cont=0;
	printf("La c%cpsula necesita que le indiques el vector direcci%cn que debe seguir en su trayectoria. Urano se halla a 3000M de kil%cmetros de %cl, si la nave se encuentra a 50M de  kil%cmetros por encima de la Tierra que est%c a 150M de  kil%cmetros, ¿Cu%cl es el vector direcci%cn que la nave debe seguir? ", 160, 162, 162, 130, 162, 160, 162, 160, 162);

	printf("\n\nV1: ");
	for ( i = 0; i < DIM; i++)
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
	for ( i = 0; i < DIM; i++)
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