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
        exit(EXIT_FAILURE);
    }
    if (cle > 25 || cle < 0){
        exit(EXIT_FAILURE);
    }
    int sizeTEXTE = strlen(texte);
    int* tableauCARACTERESCHIFFRE = NULL;
    // Allocation dynamique du message chiffrée
    tableauCARACTERESCHIFFRE = malloc(4 * (strlen(texte)));

    if (tableauCARACTERESCHIFFRE == NULL) {
        perror("Echec de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }
    int c,k = 0, cp = 0;
    for (int i = 0; i < sizeTEXTE; i++) {
        //<> Code ASCII de chaque caractère
        c = (int)texte[i];

        //<> compteurs de dépassement
        cp = 0;
        k = c;
        //<> Intervalle [65..90] <=> [A..Z] du tableau ASCII
        if (c >= 65 && c <= 90){
            //<> Si le caractère chiffré dépasse l'intervalle
            if ((c + cle) > 90) {
                //<> Récupération du nombre de pas dépassant l'intervalle [65..90]
                while (k <= 90) {cp++; k++;}
                //<> Affectation et chiffrement de chaque caractère
                tableauCARACTERESCHIFFRE[i] = 65 + (cle - cp);
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else{
                tableauCARACTERESCHIFFRE[i] = c + cle;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            }
        //<> Intervalle [a..z] du tableau ASCII
        } else if(c >= 97 && c <= 122){
            if ((c + cle) > 122) {
                while (k <= 122) {cp++; k++;}
                tableauCARACTERESCHIFFRE[i] = 97 + (cle - cp);
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else {
                tableauCARACTERESCHIFFRE[i] = c + cle;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            }
        } else{
            //<> Caractère [ESPACE] du tableau ASCII
            if (c == 32) {
                tableauCARACTERESCHIFFRE[i] = 35;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else{
                tableauCARACTERESCHIFFRE[i] = c + cle;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            }
        }
    }
    free(tableauCARACTERESCHIFFRE);
    return EXIT_SUCCESS;
}

void dechiffrer(const char *texte, int cle){

}

int affichage(){

}
