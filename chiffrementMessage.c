#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAILLE_TABLEAU_ASCII 52

int verifierAlphanumerique(const char *texte){
    int sizeTEXTE = strlen(texte);
    // Tableau contenant des correspondances en décimal des
    // caractères alphanumérique
    int* tableauASCII = NULL;
    int* tableauCARACTERES = NULL;
    tableauASCII = (int*) malloc(4 * (TAILLE_TABLEAU_ASCII)+1);
    tableauCARACTERES = (int*) malloc(sizeof(int) * strlen(texte));

    //========= VERIFICATION DE L'ALLOCATION =================//
    if (tableauASCII == NULL) {
        perror("Echec de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    if (tableauCARACTERES == NULL) {
        perror("Echec de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    //=========================================================//

    // Remplissage du tableau ASCII alphanumérique [+ SPACE]
    //>> [OPTIMISATION SEMI-POSSIBLE]
    int count = 0;
    while (count < TAILLE_TABLEAU_ASCII) {
        // CARACTERE EN MAJUSCULE [A..Z]
        for (int i = 65; i <= 90; i++) {
            tableauASCII[count] = i;
            count++;
        }
        // CARACTERE EN MINUSCULE [a...z]
        for (int i = 97; i <= 122; i++) {
            tableauASCII[count] = i;
            count++;
        }
        // espace inclus
        tableauASCII[count] = 32;
        count++;
    }

    // Remplissage du tableau des valeurs DEC
    // de chaque caractère du message
    for (int i = 0; i < sizeTEXTE; i++) {
        tableauCARACTERES[i] = (int) texte[i];
    }

    // Analyse alphanumérique de chaque caractère
    int charAlpha = 0;
    //>> [OMPTIMISATION SEMI-POSSIBLE] 
    for (int i = 0; i <= sizeTEXTE; i++) {
        for (int j = 0; j <= TAILLE_TABLEAU_ASCII; j++){
            if (tableauCARACTERES[i] == tableauASCII[j]) {
                charAlpha++;
                break;
            }
        }
    }

    // Vidage de la mémoire après utilisation des tableau
    free(tableauASCII);
    free(tableauCARACTERES);

    // vérification de l'égalité alphanumérique [+ SPACE]
    if (charAlpha == sizeTEXTE) {
        return (EXIT_SUCCESS);
    } else{
        return (EXIT_FAILURE);
    }
}

void convertirAccents(char *texte){

}

int chiffrer(char *texte, int cle){
    // appel de la fonction de vérification
    if (verifierAlphanumerique(texte) == 1){
        return EXIT_FAILURE;
    }
    // Allocation dynamique du message chiffrée
    char *messageChiffree = NULL;
    messageChiffree = malloc((strlen(texte))*sizeof(char));
    

    if (messageChiffree == NULL) {
        perror("Echec de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }



    return EXIT_SUCCESS;

}

// ========================================
/**
int main(int argc, char *argv[])
{
 
    char chaine[] = "Texte";
    char* copie=NULL;
 
    copie = copieur(chaine);
 
 
    printf("chaine vaut : %s\n", chaine);
    printf("copie vaut : %s\n", copie);
    free(copie);  surtout ne pas oublier de  libérer la mémoire alloué dans la fonction copieur 
 
    return 0;
 
}

 
char* copieur(const char *originale)
{
    char *copie=NULL;
    copie=malloc((strlen(originale)+1)*sizeof(char));
    strcpy(copie,originale);
    
    return copie;
}
**/

// ========================================

void dechiffrer(const char *texte, int cle){

}

int affichage(){

}
