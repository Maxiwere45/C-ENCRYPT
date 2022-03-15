// FICHIER C CONTENANT LES ENTETES DES FONCTIONS DE CHIFFREMENT

/**
 * @brief Vérifie si le message à chiffrer ou à déchiffrer 
 * ne comporte que des caractères alphanumériques
 * @param texte Pointeur du message
 */
void verifierAlphanumerique(char* texte);

/**
 * @brief Convertit les accents en chaine alphanumériques
 * @param texte Message contenant des caractères alphanumériques
 */
void convertirAccents(char texte);

/**
 * @brief Retourne une chaine de caractères chiffré
 * 
 * @param texte Message à chiffrer
 * @return char 
 */
char chiffrer(char texte);

/**
 * @brief Retourne une chaine de caractères déchiffré 
 * 
 * @param texte Message à déchiffrer
 * @return char 
 */
char dechiffrer(char texte);

/**
 * @brief Interface
 * 
 * @param texte Message à chiffrer ou à déchiffrer
 */
void affichage(char texte);