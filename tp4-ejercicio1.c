#include <stdio.h>
#include <stdlib.h>
#include "sign.h"

#define MAXTIMES    5
// CRUCE 1
#define RUTA1_1 "Abriste una puerta."
#define RUTA2_1 "Te retiras."

// CRUCE 2
#define RUTA1_2 "Te adentras a la oscuridad."
#define RUTA2_2 "Te horrorizas y te cuestionas seguir."

// CRUCE 3
#define RUTA1_3 "Algo te toca."
#define RUTA2_3 "Huyes."

// CRUCE 4
#define RUTA1_4 "Huyes. Encuentras una puerta entre abierta a la izquierda."
#define RUTA2_4 "Tropiezas y ves una luz en una puerta a la derecha."

// CRUCE 5
#define RUTA1_5 "Despiertas."
#define RUTA2_5 "Despiertas. Y vuelves a empezar en el mismo lugar."

int i;
int playagain = 1;
int cantidad = 0;
int opciones[MAXTIMES][1];
int jugador = 1;


void crearyguardar(char *decision){
    FILE * arch;

    arch = fopen("archivo.log", "a+");

    if(arch == NULL){
        printf("ERROR");
        exit(1);
    }
    fflush(arch);

    fprintf(arch, "JUGADOR: %d \t %s \n", jugador, decision);
    fclose(arch);
}


//esto lo vamos a usar para leer las decisiones tomadas del TXT
char * decisiones(int opcion, int decision){

    switch(opcion){
        case 0:
            if(decision == 0){
                return RUTA1_1;
            }else{
                return RUTA2_1;
            }
        case 1:
            if(decision == 0){
                return RUTA1_2;
            }else{
                return RUTA2_2;
            }
        case 2:
            if(decision == 0){
                return RUTA1_3;
            }else{
                return RUTA2_3;
            }
        case 3:
            if(decision == 0){
                return RUTA1_4;
            }else{
                return RUTA2_4;
            }
        case 4:
            if(decision == 0){
                return RUTA1_5;
            }else{
                return RUTA2_5;
            }

    }
}

struct listado{
    int id;
    char nombre[32];
    int opciones[MAXTIMES][1];
};

void jugar(){
    struct listado Jugador;
    printf("/////// READY PLAYER %d //////// \n", jugador);
    i = 0;
    while(i < 5){
        printf("Elige tu camino, izquierda(1), derecha(0) \n");
        scanf("%d", &Jugador.opciones[i][0]);


        char * valor = decisiones(i,Jugador.opciones[i][0]);
        crearyguardar(valor);
        printf("ESTADO: %s \n", valor);
        i++;
    }

    if(i == 5){
        puts("/////////////////////////////// \n"
             "/////////////////////////////// \n"
             "/////////////////////////////// \n");
        printf("Final de partida, amigo \n");
        printf("WANNA PLAY AGAIN? ? ?");
        printf("\n\n JUGAR DE NUEVO(1) || VER REGISTRO DE JUGADAS(2) || NO JUGAR: any other value \n\n");

        scanf("%d", &playagain);
        Jugador.id = jugador;
        jugador++;

        if(playagain == 2){
            char *filename = "archivo.log";
            FILE *fptr = NULL;

            if((fptr = fopen(filename,"r")) == NULL)
            {
                fprintf(stderr,"error opening %s\n",filename);
                return 1;
            }

            print_image(fptr);
            fclose(fptr);

            char read_string[128];

            while(fgets(read_string,sizeof(read_string),fptr) != NULL)
            printf("%s",read_string);

            playagain = 1;


        }else if(playagain == 1){
            jugar();
        }else{

            printf("FAREWELL, my friend \n");
            sign();

        }

    }

}

int main(){

    while(playagain == 1){
        jugar();
    }





    system("pause"); // nos evitamos que se cierre de golpe
    return 0;
}
