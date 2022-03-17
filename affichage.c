#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"

int main(){
    char monMessage[] = "This is the beginning of meditation";
    char* pointeurMessage = monMessage;


    char *monMessagechiffre = NULL;
    monMessagechiffre = malloc(sizeof(char) * strlen(monMessage));
    stpcpy(monMessagechiffre,monMessage);
    int cle = 8;

    if (verifierAlphanumerique(monMessage) == 1) {
        perror("Ce message n'est pas conforme au chiffrement !");
        return EXIT_FAILURE;
    }

    if (cle > 26 || cle < 0) {
        perror("Clé de chiffrement invalide ! [0 < clé < 26]");
        return EXIT_FAILURE;
    }

    printf("====CHIFFREMENT=======\n");
    chiffrer(monMessagechiffre,cle);
    printf("%s\n", monMessagechiffre);
    free(monMessagechiffre);
    return EXIT_SUCCESS;
}