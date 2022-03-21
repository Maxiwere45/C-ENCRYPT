#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAILLE_TABLEAU_ASCII 52

int verifierAlphanumerique(const char *texte){
    int sizeTEXTE = strlen(texte);
    // Tableau contenant des correspondances en d�cimal des
    // caract�res alphanum�rique
    int* tableauASCII = NULL;
    int* tableauCARACTERES = NULL;
    tableauASCII = (int*) malloc(4 * (TAILLE_TABLEAU_ASCII)+1);
    tableauCARACTERES = (int*) malloc(sizeof(int) * strlen(texte));

    //========= VERIFICATION DE L'ALLOCATION =================//
    if (tableauASCII == NULL) {
        perror("Echec de l'allocation m�moire");
        exit(EXIT_FAILURE);
    }

    if (tableauCARACTERES == NULL) {
        perror("Echec de l'allocation m�moire");
        exit(EXIT_FAILURE);
    }
    //=========================================================//

    // Remplissage du tableau ASCII alphanum�rique [+ SPACE]
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
    // de chaque caract�re du message
    for (int i = 0; i < sizeTEXTE; i++) {tableauCARACTERES[i] = (int) texte[i];}

    // Analyse alphanum�rique de chaque caract�re
    int charAlpha = 0;
    //>> [OMPTIMISATION SEMI-POSSIBLE] 
    for (int i = 0; i <= sizeTEXTE; i++) {
        for (int j = 0; j <= TAILLE_TABLEAU_ASCII; j++){
            if (tableauCARACTERES[i] == tableauASCII[j]){charAlpha++; break;}
        }
    }
    // Vidage de la m�moire apr�s utilisation des tableau
    free(tableauASCII);free(tableauCARACTERES);

    // v�rification de l'�galit� alphanum�rique [+ SPACE]
    if (charAlpha == sizeTEXTE) {return (EXIT_SUCCESS);}
    else{return (EXIT_FAILURE);}
}

void convertirAccents(char *texte){

}

int chiffrer(char *texte, int cle){
    // appel de la fonction de v�rification
    if (verifierAlphanumerique(texte) == 1){exit(EXIT_FAILURE);}
    if (cle > 25 || cle < 0){exit(EXIT_FAILURE);}
    int sizeTEXTE = strlen(texte);
    int* tableauCARACTERESCHIFFRE = NULL;
    // Allocation dynamique du message chiffr�e
    tableauCARACTERESCHIFFRE = malloc(4 * (strlen(texte)));
    if (tableauCARACTERESCHIFFRE == NULL) {
        perror("Echec de l'allocation m�moire");
        exit(EXIT_FAILURE);
    }
    int corr_ascii,over_flow_garbage = 0, over_flow = 0;
    for (int i = 0; i < sizeTEXTE; i++) {
        //<> Code ASCII de chaque caract�re
        corr_ascii = (int)texte[i];
        //<> compteurs de d�passement
        over_flow = 0;
        over_flow_garbage = corr_ascii;
        //<> Intervalle [65..90] <=> [A..Z] du tableau ASCII
        if (corr_ascii >= 65 && corr_ascii <= 90){
            //<> Si le caract�re chiffr� d�passe l'intervalle
            if ((corr_ascii + cle) > 90) {
                //<> R�cup�ration du nombre de pas d�passant l'intervalle [65..90]
                while (over_flow_garbage <= 90) {over_flow++; over_flow_garbage++;}
                //<> Affectation et chiffrement de chaque caract�re
                tableauCARACTERESCHIFFRE[i] = 65 + (cle - over_flow);
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else{
                tableauCARACTERESCHIFFRE[i] = corr_ascii + cle;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            }
        //<> Intervalle [a..z] du tableau ASCII
        } else if(corr_ascii >= 97 && corr_ascii <= 122){
            if ((corr_ascii + cle) > 122) {
                while (over_flow_garbage <= 122) {over_flow++; over_flow_garbage++;}
                tableauCARACTERESCHIFFRE[i] = 97 + (cle - over_flow);
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else {
                tableauCARACTERESCHIFFRE[i] = corr_ascii + cle;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            }
        } else{
            //<> Caract�re [ESPACE] du tableau ASCII
            if (corr_ascii == 32) {
                tableauCARACTERESCHIFFRE[i] = 35;
                texte[i] = (char) tableauCARACTERESCHIFFRE[i];
            } else{
                tableauCARACTERESCHIFFRE[i] = corr_ascii + cle;
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
