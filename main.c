#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"
#define TAILLE_TABLEAU_ASCII 52

int main(){
    char monMessage[] = "Hello World";
    char* pointeurMessage = monMessage;
    
    int ok = verifierAlphanumerique(pointeurMessage);

    if (ok)
    {
        printf("Tout est ok !");
    }
    
    return (EXIT_SUCCESS);
}

/**
    int count = 0;
    while (count < TAILLE_TABLEAU_ASCII)
    {
        for (int i = 65; i <= 90; i++) {
            tableauASCII[count] = i;
            count++;
        }
        for (int i = 97; i <= 122; i++) {
            tableauASCII[count] = i;
            count++;
        }
        tableauASCII[count] = 32;
        count++;
    }

     for (int i = 0; i < count; i++)
    {
        printf("Valeur: %d\n",tableauASCII[i]);
    }
    **/