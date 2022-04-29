#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int verifierAlphanumerique(const char *texte){
    int sizeTEXTE = strlen(texte) - 1;
    int count = 0;
    int counter = 0;
    for (int j = 0; j < sizeTEXTE; j++){
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
    if (counter == sizeTEXTE) {
        return EXIT_SUCCESS;
    } else{
        return EXIT_FAILURE;
    } 
}

void convertirAccents(char *texte){
}

int verifierCleVigenere(char *cle){
    int len = strlen(cle);
    int caract,count = 0,i = 0;
    
    while (i < len){
        caract = (int) cle[i];
        if (caract > 90 || caract < 65){
            count--;
        }
        count++; 
        i++;
    }

    if (count == len) {
        return EXIT_SUCCESS;
    } else{
        return EXIT_FAILURE;
    }
    
    
}

int chiffrerC(char *texte, const int cle){
    int sizeTEXTE = strlen(texte) - 1;
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

int dechiffrerC(char *texte, const int cle){
    int sizeTEXTE = strlen(texte) - 1;
    int caracterechiffre;
    int corr_ascii,over_flow_garbage = 0, over_flow = 0;
    for (int i = 0; i < sizeTEXTE; i++) {
        //<> Code ASCII de chaque caractère
        corr_ascii = (int) texte[i];
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
                
                    caracterechiffre = 122 - (cle - over_flow);
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
    // Tableau de vigénère
    char tableauVigenere2D[26][26];
    char caractere_mess;
    int indexeur = 65,
    long_mess = (int) strlen(texte) - 1,
    long_cle = (int) strlen(cle),
    incle = 0,i = 0,j,k;
    for (int p = 0; p < 26; p++){
        for (int j = 0; j < 26; j++) {
            // Correspondance ASCII
            tableauVigenere2D[p][j] = (char) indexeur;
            indexeur++;
            if (indexeur > 90) {indexeur = 65;}
        }
        indexeur = 65 + (p+1);
    }
    while (i < long_mess) {
        if ((int) texte[i] == 64 ||
            (int) texte[i] == 44 ||
            (int) texte[i] == 46 ||
            (int) texte[i] == 32) {
            i++;
        }
        //>> Un problème empêche de skip le caractère SPACE :(
        if ((int) texte[i] == 39) {
            texte[i] = 39;
            i++;
        }
        caractere_mess = toupper(texte[i]);
        j = 0;
        k = 0;
        while (tableauVigenere2D[0][j] != caractere_mess){ j++;}
        while (tableauVigenere2D[k][0] != cle[incle]){k++;}
        texte[i] = tableauVigenere2D[k][j];
        incle++;
        if (incle >= long_cle) {incle = 0;}
        i++;
    }
    return EXIT_SUCCESS;
}

int dechiffrerV(char *texte, const char *cle){
    
}