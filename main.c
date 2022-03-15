#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"
#define TAILLE_TABLEAU_ASCII 52

int main(){
    char monMessage[] = "This is the beginning of meditation";
    char* pointeurMessage = monMessage;
    
    int ok = verifierAlphanumerique(pointeurMessage);
    if (ok == 0)
    {
        printf("Ce texte est conforme au chfiffrement !\n");
    } else{
        printf("Ce texte n'est pas conforme au chfiffrement !\n");
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