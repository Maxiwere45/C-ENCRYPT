// FICHIER C CONTENANT LES ENTETES DES FONCTIONS DE CHIFFREMENT

/**
 * @brief V�rifie si le message � chiffrer ou � d�chiffrer 
 * ne comporte que des caract�res alphanum�riques
 * @param texte Pointeur du message
 * @return int
 */
int verifierAlphanumerique(char *texte);

/**
 * @brief Convertit les accents en chaine alphanum�riques
 * @param texte Message contenant des caract�res alphanum�riques
 */
void convertirAccents(char *texte);

/**
 * @brief Crypte un message
 * @param texte Message � chiffrer
 * @param cle Cl� de chiffrement
 * @return int 
 */
int chiffrer(char *texte, int cle);

/**
 * @brief D�chiffre un message chiffr�
 * 
 * @param texte Message � d�chiffrer
 * @param cle Cl� de d�chiffrement
 * @return int
 */
int dechiffrer(char *texte, int cle);

/**
 * @brief Interface
 * 
 * @param texte Message � chiffrer ou � d�chiffrer
 * @return int
 */
int affichage();