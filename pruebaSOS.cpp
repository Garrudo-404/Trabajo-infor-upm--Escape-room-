#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

#define DIM 50



int prueba3(void);


int main()
{
    //SOS
    prueba3();

}

int prueba3() {//codigo morse
    int intentos = 3,test ; char morse[DIM];
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
                printf("\nEl codigo es incorrecto, la senal sera inhibida.\nVuelve a intentarlo, este es tu ultimo intento\n");
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
