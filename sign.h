#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 128

void print_image(FILE *fptr);

int sign(void)
{

    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    char *filename = "sign/image.txt";
    FILE *fptr = NULL;

    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr);

    fclose(fptr);
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// ALEJA EL ZOOM PARA VER EL DIBUJO ASCII - JNC \n");
    printf("////////// FAREWELL MY FRIEND \\\\\\\\\\ \n");

    system("pause");

    return 0;
}

void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
