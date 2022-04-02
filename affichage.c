#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h" 

int main(){
    char monMessage[] = "This is the beginning of meditation bro";
    char* pointeurMessage = monMessage;


    char *monMessagechiffre = NULL;
    monMessagechiffre = malloc(sizeof(char) * strlen(monMessage));
    stpcpy(monMessagechiffre,monMessage);
    int cle = 3;

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

            printf("=======DECHIFFREMENT=======\n");
            dechiffrer(monMessagechiffre,cle);
            printf("%s\n", monMessagechiffre);
            free(monMessagechiffre);
            return EXIT_SUCCESS;
        }
    }
}