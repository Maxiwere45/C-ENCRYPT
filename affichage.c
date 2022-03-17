#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chiffrementMessage.h"

int main(){
    char monMessage[] = "This is the beginning of, meditation and sometime we see new thinghs";
    char* pointeurMessage = monMessage;
    
    int ok = verifierAlphanumerique(pointeurMessage);
    if (ok == 0){
        printf("Ce message est conforme au chfiffrement !\n");
        
    } else{
        printf("Ce message n'est pas conforme au chfiffrement !\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}