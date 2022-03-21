// FICHIER C CONTENANT LES ENTETES DES FONCTIONS DE CHIFFREMENT

/**
 * @brief Vérifie si le message à chiffrer ou à déchiffrer 
 * ne comporte que des caractères alphanumériques
 * @param texte Pointeur du message
 * @return int
 */
int verifierAlphanumerique(char *texte);

/**
 * @brief Convertit les accents en chaine alphanumériques
 * @param texte Message contenant des caractères alphanumériques
 */
void convertirAccents(char *texte);

/**
 * @brief Crypte un message
 * @param texte Message à chiffrer
 * @param cle Clé de chiffrement
 * @return int 
 */
int chiffrer(char *texte, int cle);

/**
 * @brief Déchiffre un message chiffré
 * 
 * @param texte Message à déchiffrer
 * @param cle Clé de déchiffrement
 * @return int
 */
int dechiffrer(char *texte, int cle);

/**
 * @brief Interface
 * 
 * @param texte Message à chiffrer ou à déchiffrer
 * @return int
 */
int affichage();