#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"

int main(){
    char monMessage[] = "Aujourdhui le soleil s est leve";
    char* pointeurMessage = monMessage;


    char *monMessagechiffre = NULL;
    monMessagechiffre = malloc(sizeof(char) * strlen(monMessage));
    stpcpy(monMessagechiffre,monMessage);
    int cle = 24;

    if (verifierAlphanumerique(monMessage) == 1) {
        perror("Ce message n'est pas conforme au chiffrement !");
        exit(EXIT_FAILURE);
    } else {
        if (cle > 26 || cle < 0) {
        perror("Clé de chiffrement invalide !");
        exit(EXIT_FAILURE);
        } else{
            printf("====CHIFFREMENT=======\n");
            chiffrer(monMessagechiffre,cle);
            printf("%s\n", monMessagechiffre);
            free(monMessagechiffre);
            return EXIT_SUCCESS;
        }
    }
}