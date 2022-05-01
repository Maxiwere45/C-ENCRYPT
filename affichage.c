/*
*****************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : Sujet N°3                                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :  CHIFFREMENT DE MESSAGES                                        *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Amdjad Anrifou                                               *
*                                                                             *
*  Nom-prénom2 : Bentaïla Fabio                                               *
*                                                                             *
*  Nom-prénom3 : Thomas Daure                                                 *
*                                                                             *
*  Nom-prénom4 : Kopec Wiktor                                                 *
*                                                                             *
*******************************************************************************
*/

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
    // ----------------------------------------------
    FILE *data = fopen("./data/content.txt","a+");
    FILE *description = fopen("./data/description_aff.txt", "r");
    if (data == NULL) {
        perror("Ouverture du fichier content.txt impossible !");
        exit(EXIT_FAILURE);
    }
    if (description == NULL) {
        perror("Ouverture du fichier description_aff.txt impossible !");
        exit(EXIT_FAILURE);
    }
    char sep[] = "---------------------------------";
    char *reponse = NULL;
    reponse = (char*) malloc(4);
    int rep;
    signed char desc[10000];
    // ---------------------------------------------- 
    if (copy == NULL){
        printf("Erreur d'allocation détécté !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(description)) {
        fgets(desc, 10000, description);
        printf("%s", desc);
    }

    printf("\n\n> Entrez du texte: \n >> ");
    nbCharLu = getline(&copy, &tailleMESS, stdin);
    if (nbCharLu > (MAX_SIZE_MESSAGE+1)){
        printf("Message trop volumineux !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }
    message = (char*) malloc(sizeof(char) * nbCharLu);
    if (message == NULL){
        printf("Erreur d'allocation détécté !\n");
        printf("\tÉxtinction du programme...\n");
        exit(EXIT_FAILURE);
    }
    strncpy(message,copy,nbCharLu);
    free(copy);
    printf("---------------------------------------------");
    printf("\nQue souhaitez-vous faire de ce texte ?\n");
    printf(" -> 1 [Chiffrer]\n");
    printf(" -> 2 [Déchiffrer]\n");
    printf(" -> 3 [Quitter]\n");
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
            printf("Texte non conforme à un chiffrement !\n");
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
            if (messageChiffre == NULL){
                printf("Erreur d'allocation détécté !\n");
                printf("\tÉxtinction du programme...\n");
                exit(EXIT_FAILURE);
            }
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
                    printf("Texte chiffré: %s\n",messageChiffre);
                    printf("Voulez-vous sauvegarder ce texte chiffré [oui/non] ? >> ");
                    rep = scanf("%s", reponse);
                    if (strcmp(reponse, "oui") == 0) {
                        fprintf(data,"%s\nType de chiffrement : César\nClé de déchiffrement: %d\nMessage:\n%s",sep,cle,messageChiffre);
                        printf("Message sauvergardé dans le fichier data/content.txt !");
                    }
                    free(messageChiffre);
                    free(reponse);
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
                    printf("Voulez-vous sauvegarder le message ? >> ");
                    rep = scanf("%s", reponse);
                    if (strcmp(reponse, "oui") == 0) {
                        fprintf(data,"%s\nType de chiffrement : Vigénère\nClé de déchiffrement: %s\nMessage:\n%s",sep,cleV,messageChiffre);
                        printf("Message sauvergardé dans le fichier data/content.txt !");
                    }
                    free(messageChiffre);
                    free(reponse);
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
                    printf("Texte déchiffré: %s\n",messageDechiffre);
                    free(messageDechiffre);
                    free(cleV);
                    break;
                // Vigénère
                case 2:
                    printf("=============== DÉCHIFFREMENT PAR VIGENERE ===============\n");
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
                    printf("Texte dechiffré : %s\n", messageDechiffre);
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
        case 3:
            free(copyCle);
            free(message);
            break;
        default:
            printf("Valeur incorrecte detecté !\n");
            printf("\tÉxtinction du programme...\n");
            exit(EXIT_FAILURE);
            break;
    }
    fclose(data);
    fclose(description);
    printf("\nFin du programme...\n");
    return EXIT_SUCCESS;
}