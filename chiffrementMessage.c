#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int verifierAlphanumerique(const char *texte){
    int sizeTEXTE = strlen(texte);
    int count = 0;
    int counter = 0;
    for (int j = 0; j < strlen(texte); j++){
        for (int k = 65; k < 90; k++)
        {
            if ((int) texte[j] == k){counter++;}
        }
        for (int k = 97; k < 122; k++){
            if ((int) texte[j] == k){counter++;}
        }
        // [ESPACE, virgule, apostrophe] inclus
        if ((int) texte[j] == 32 || 
            (int) texte[j] == 39 ||
            (int) texte[j] == 44 || 
            (int) texte[j] == 46){
            counter++;
        }
    }
    if (counter == strlen(texte)) {
        return EXIT_SUCCESS;
    } else{
        return EXIT_FAILURE;
    } 
}

void convertirAccents(char *texte){

}

int chiffrerC(char *texte, int cle){
    // appel de la fonction de vérification
    if (verifierAlphanumerique(texte) == 1){exit(EXIT_FAILURE);}
    if (cle > 25 || cle < 0){exit(EXIT_FAILURE);}
    int sizeTEXTE = strlen(texte);
    int corr_ascii,caracterechiffre,over_flow_garbage = 0, over_flow = 0;
    for (int i = 0; i < sizeTEXTE; i++) {
        //<> Code ASCII de chaque caractère
        corr_ascii = (int)texte[i];
        //<> compteurs de dépassement
        over_flow = 0;
        over_flow_garbage = corr_ascii;
        
        //<> Intervalle [65..90] <=> [A..Z] du tableau ASCII
        if (corr_ascii >= 65 && corr_ascii <= 90){
            //<> Si le caractère à chiffrer dépasse l'intervalle
            if ((corr_ascii + cle) > 90) {
                //<> Récupération du nombre de pas dépassant l'intervalle [65..90]
                while (over_flow_garbage <= 90) {over_flow++; over_flow_garbage++;}
                //<> Affectation et chiffrement de chaque caractère
                caracterechiffre = 65 + (cle - over_flow);
                texte[i] = (char) caracterechiffre;
            } else{
                caracterechiffre = corr_ascii + cle;
                texte[i] = (char) caracterechiffre;
            }
        //<> Intervalle [a..z] du tableau ASCII
        } else if(corr_ascii >= 97 && corr_ascii <= 122){
            if ((corr_ascii + cle) > 122) {
                while (over_flow_garbage <= 122) {over_flow++; over_flow_garbage++;}
                caracterechiffre = 97 + (cle - over_flow);
                texte[i] = (char) caracterechiffre;
            } else {
                caracterechiffre = corr_ascii + cle;
                texte[i] = (char) caracterechiffre;
            }
        } else{
            //<> Caractères orthographique du tableau ASCII
            if (corr_ascii == 32) {
                caracterechiffre = 35;
                texte[i] = (char) 35;
            } else if(corr_ascii == 39){texte[i] = (char) 42;
            } else if(corr_ascii == 44){texte[i] = (char) 45;
            } else if(corr_ascii == 46){texte[i] = (char) 47;
            } else{texte[i] = (char) corr_ascii + cle;}
        }
    }
    return EXIT_SUCCESS;
}

int dechiffrerC(char *texte, int cle){
    // appel de la fonction de vérification
    if (cle > 25 || cle < 0){exit(EXIT_FAILURE);}
    int sizeTEXTE = strlen(texte);
    int caracterechiffre;
    int corr_ascii,over_flow_garbage = 0, over_flow = 0;
    for (int i = 0; i < sizeTEXTE; i++) {
        //<> Code ASCII de chaque caractère
        corr_ascii = (int)texte[i];
        //<> compteurs de dépassement
        over_flow = 0;
        over_flow_garbage = corr_ascii;
        //<> Intervalle [65..90] <=> [A..Z] du tableau ASCII
        if (corr_ascii >= 65 && corr_ascii <= 90){
            //<> Si le caractère à déchiffrer dépasse l'intervalle
            if ((corr_ascii - cle) < 65) {
                //<> Récupération du nombre de pas dépassant l'intervalle [65..90]
                while (over_flow_garbage >= 65) {over_flow++; over_flow_garbage--;}
                //<> Affectation et déchiffrement de chaque caractère
                caracterechiffre = 90 - (cle - over_flow);
                texte[i] = (char) caracterechiffre;
            } else{
                caracterechiffre = corr_ascii - cle;
                texte[i] = (char) caracterechiffre;
            }
            //<> Intervalle [a..z] du tableau ASCII
        } else if(corr_ascii >= 97 && corr_ascii <= 122){
            if ((corr_ascii - cle) < 97) {
                while (over_flow_garbage >= 97) {over_flow++; over_flow_garbage--;}
                caracterechiffre = 97 - (cle - over_flow);
                texte[i] = (char) caracterechiffre;
            } else {
                caracterechiffre = corr_ascii - cle;
                texte[i] = (char) caracterechiffre;
            }
        } else{
            //<> Caractère [ESPACE] du tableau ASCII
            if (corr_ascii == 35) {texte[i] = (char) 32;
            } else if(corr_ascii == 42){texte[i] = (char) 39;
            } else if(corr_ascii == 45){texte[i] = (char) 44;
            } else if(corr_ascii == 47){texte[i] = (char) 46;
            } else{ caracterechiffre = corr_ascii + cle;
                texte[i] = (char) caracterechiffre;}
        }
    }
    return EXIT_SUCCESS;
}

int chiffrerV(char *texte, char *cle){
    // Création du tableau de vigénère
    char tableauVigenere2D[26][26];
    int indexeur = 65;
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++) {
            // Correspondance ASCII
            tableauVigenere2D[i][j] = (char) indexeur;
            indexeur++;
            if (indexeur > 90) {
                indexeur = 65;
            }
        }
        indexeur = 65 + (i+1);
    }
}

int dechiffrerV(char *texte, char *cle){
    
}

int affichage(){
    return EXIT_SUCCESS;
}
