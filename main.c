#include <stdio.h>
#include <stdlib.h>
#define TAILLE_TABLEAU_ASCII 50

int main(){
    //char h = 'e';
    //printf("Lettre : %c - Valeur ASCII : %d",h,h);

    int* tableauASCII = (int*) malloc(4 * TAILLE_TABLEAU_ASCII);
    if (tableauASCII == NULL) {
        perror("Echec malloc");
        exit(EXIT_FAILURE);
    }

    tableauASCII[0] = 56;
    printf("Valeur: %d",tableauASCII[0]);

    free(tableauASCII);
    return (EXIT_SUCCESS);
    
}