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

// FICHIER C CONTENANT LES ENTETES DES FONCTIONS

/**
 * @brief Vérifie si le message à chiffrer ou à déchiffrer 
 * ne comporte que des caractères alphanumériques (avec certaines caractères).
 * Retourne 0 si ok, 1 sinon
 * @param texte Message
 * @return int
 */
int verifierAlphanumerique(const char *texte);

/**
 * @brief Convertit les accents en chaine alphanumériques 
 * @param texte Message contenant des accents
 */
void convertirAccents(char *texte);

/**
 * @brief Crypte un message par la méthode César
 * @param texte Message à chiffrer
 * @param cle Clé de chiffrement
 * @return int 
 */
int chiffrerC(char *texte, const int cle);

/**
 * @brief Déchiffre un message chiffré par la méthode César
 * 
 * @param texte Message à déchiffrer
 * @param cle Clé de déchiffrement
 * @return int
 */
int dechiffrerC(char *texte, const int cle);

/**
 * @brief Vérifie la si la clé fournie pour coder ou décoder un message par
 * la méthode de vigénère est valide
 * 
 * @param cle Clé à vérifier
 * @return int 
 */
int verifierCleVigenere(char *cle);

/**
 * @brief Crypte un message par la méthode Vigénère
 * 
 * @param texte Message a chiffrer
 * @param cle Clé de chiffrement
 * @return int 
 */
int chiffrerV(char *texte, char *cle);

/**
 * @brief Dechiffre un message par la méthode Vigénère
 * 
 * @param texte Message a dechiffrer
 * @param cle Clé de dechiffrement
 * @return int 
 */
int dechiffrerV(char *texte, char *cle);
