#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"

int main(){
    char monMessage[] = "This is the beginning of meditation";
    char* pointeurMessage = monMessage;
    
    int ok = verifierAlphanumerique(pointeurMessage);
    if (ok == 0){
        printf("Ce message est conforme au chiffrement !\n");
        printf("%s \n",monMessage);
    } else{
        printf("Ce message n'est pas conforme au chfiffrement !\n");
        return (EXIT_FAILURE);
    }



    return (EXIT_SUCCESS);
}