#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"
#define MAX_SIZE_MESSAGE 564
#define MAX_SIZE_KEY 20

int main(){
    int value,cle,temp,ret,ver_alpha,nbCharLu = 0, ver_cle;
    size_t tailleMESS = 0,tailleCLE = 0;
    char *cleV = NULL;
    char *message = NULL;
    char *messageChiffre = NULL;
    char *messageDechiffre = NULL;
    char *copy = NULL;
    char *copyCle = NULL;
    copyCle = (char*) malloc(sizeof(char) * MAX_SIZE_KEY);
    copy = (char*) malloc(sizeof(char) * MAX_SIZE_MESSAGE);
    if (copy == NULL){
        printf("Erreur interne détécté !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }
    printf("=============== >> C-ENCRYPT << ===============\n");
    printf(">> Ce programme peut chiffrer ou déchiffrer un message avec plus de 564 caractères (une paragraphe)\n");
    printf("> Entrez un message: \n >> ");
    nbCharLu = getline(&copy, &tailleMESS, stdin);
    if (nbCharLu > (MAX_SIZE_MESSAGE+1)){
        printf("Message trop volumineux !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }
    message = (char*) malloc(sizeof(char) * nbCharLu);
    strncpy(message,copy,nbCharLu);
    free(copy);
    
    printf("Que souhaitez-vous faire de ce message ?\n");
    printf(" -> 1 [Chiffrer]\n");
    printf(" -> 2 [Déchiffrer]\n");
    printf(" >> ");
    ret = scanf("%d", &temp);
    if (ret != 1) {
        printf("\nValeur incorrecte détécté !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }
    switch (temp) {
        // Chiffrement
        case 1:
        ver_alpha = verifierAlphanumerique(message);
        if (ver_alpha != 0){
            printf("Message non-conforme à un chiffrement !\n");
            printf("\tÉxtinction du programme...\n");
            exit(EXIT_FAILURE);
        }
            printf("\n\nChoisissez une méthode de chiffrement : \n");
            printf(" > 1 [César]\n");
            printf(" > 2 [Vigénère]\n");
            printf(" >> ");
            ret = scanf("%d", &value);
            if (ret != 1) {
                printf("Valeur incorrecte detecté !\n");
                printf("\tÉxtinction du programme...\n");
                exit(EXIT_FAILURE);
            }
            messageChiffre = (char*) malloc(sizeof(char) * nbCharLu);
            strncpy(messageChiffre,message, nbCharLu);
            free(message);
            switch (value){
                // César
                case 1:
                    printf("=============== CHIFFREMENT PAR CÉSAR ===============\n");
                    printf("Entrez la clé de chiffrement : ");
                    ret = scanf("%d", &cle);
                    if (ret != 1) {
                        printf("Valeur incorrecte detecté !\n");
                        printf("\tÉxtinction du programme...\n");
                        exit(EXIT_FAILURE);
                    }
                    while (cle < 1 || cle > 25){
                        printf("Veuiller choisir une clé comprise entre 1 et 25 !\n");
                        printf("Clé : ");
                        ret = scanf("%d", &cle);
                        if (ret != 1) {
                            printf("Valeur incorrecte detecté !\n");
                            printf("\tÉxtinction du programme...\n");
                            exit(EXIT_FAILURE);
                        }
                    }
                    printf("Chiffrement en cours...\n");
                    temp = chiffrerC(messageChiffre, cle);
                    printf("Message chiffré: %s\n",messageChiffre);
                    free(messageChiffre);
                    break;
                // Vigénère
                case 2:
                    printf("=============== CHIFFREMENT PAR VIGENERE ===============\n");
                    printf("Entrez la clé de chiffrement [MAJUSCULE et < 20]:\n >> ");
                    ret = scanf("%s", copyCle);
                    cleV = (char*) malloc(1 * strlen(copyCle));
                    strcpy(cleV,copyCle);
                    ver_cle = verifierCleVigenere(cleV);
                    if (strlen(copyCle) > MAX_SIZE_KEY ||
                        ret != 1 ||
                        ver_cle != 0) {
                        printf("Clé invalide !\n");
                        printf("\tÉxtinction du programme...\n");
                        exit(EXIT_FAILURE);
                    }
                    printf("Chiffrement en cours...\n");
                    chiffrerV(messageChiffre,cleV);
                    printf("Message chiffré : \n%s\n", messageChiffre);
                    free(messageChiffre);
                    free(cleV);
                default:
                    break;
            }
            break;
        // Déchiffrement
        case 2:
            messageDechiffre = (char*) malloc(sizeof(char) * nbCharLu);
            strncpy(messageDechiffre,message,nbCharLu);
            free(message);
            printf("\n\nChoisissez une méthode de déchiffrement : \n");
            printf(" > 1 [César]\n");
            printf(" > 2 [Vigénère]\n");
            printf(" >> ");
            ret = scanf("%d", &value);
            if (ret != 1) {
                printf("Valeur incorrecte detecté !\n");
                printf("\tÉxtinction du programme...\n");
                exit(EXIT_FAILURE);
            }
            switch (value){
                // César
                case 1:
                    printf("=============== DÉCHIFFREMENT PAR CÉSAR ===============\n");
                    printf("Entrez la clé de déchiffrement : ");
                    ret = scanf("%d", &cle);
                    if (ret != 1) {
                        printf("Valeur incorrecte detecté !\n");
                        printf("\tÉxtinction du programme...\n");
                        exit(EXIT_FAILURE);
                    }
                    while (cle < 1 || cle > 25){
                        printf("Veuiller choisir une clé comprise entre 1 et 25 !\n");
                        printf("Clé : ");
                        ret = scanf("%d", &cle);
                        if (ret != 1) {
                            printf("Valeur incorrecte detecté !\n");
                            printf("\tÉxtinction du programme...\n");
                            exit(EXIT_FAILURE);
                        }
                    }
                    printf("déchiffrement en cours...\n");
                    temp = dechiffrerC(messageDechiffre, cle);
                    printf("Message déchiffré: %s\n",messageDechiffre);
                    free(messageDechiffre);
                    free(cleV);
                    break;
                // Vigénère
                case 2:
                    printf("=============== DÉCHIFFREMENT DE VIGENERE ===============\n");
                    printf("Entrez la clé de déchiffrement [MAJUSCULE et < 20]: ");
                    ret = scanf("%s", copyCle);
                    cleV = (char*) malloc(1 * strlen(copyCle));
                    strcpy(cleV,copyCle);
                    ver_cle = verifierCleVigenere(cleV);
                    if (strlen(copyCle) > MAX_SIZE_KEY ||
                        ret != 1 ||
                        ver_cle != 0) {
                        printf("Clé invalide !\n");
                        printf("\tÉxtinction du programme...\n");
                        exit(EXIT_FAILURE);
                    }
                    printf("Déchiffrement en cours...\n");
                    dechiffrerV(messageDechiffre,cleV);
                    printf("Message dechiffré : %s\n", messageDechiffre);
                    free(messageDechiffre);
                    free(cleV);
                    break;
                default:
                    printf("Erreur detecté !\n");
                    printf("\tÉxtinction du programme...\n");
                    exit(EXIT_FAILURE);
                    break;
            }
            break;
        default:
            printf("Valeur incorrecte detecté !\n");
            printf("\tÉxtinction du programme...\n");
            exit(EXIT_FAILURE);
            break;
    }
    return EXIT_SUCCESS;
}