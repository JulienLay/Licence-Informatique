#include <stdio.h>
#define BASE 60

/* Transmission d'informations en sortie : passage de parametres par adresse */
void Conversion1(int Duree, int *pHeures, int *pMinutes, int *pSecondes) {

    *pHeures = Duree/(BASE*BASE);
    Duree = Duree%(BASE*BASE);
    *pMinutes = Duree/BASE;
    *pSecondes = Duree%BASE;
}

#define INDH 0
#define INDM 1
#define INDS 2

/* Transmission d'informations en sortie : passage d'un tableau en parametre */
void Conversion2(int Duree, int hms[]) {

    hms[INDH] = Duree/(BASE*BASE);
    Duree = Duree%(BASE*BASE);
    hms[INDM] = Duree/BASE;
    hms[INDS] = Duree%BASE;
}

int main(void) {

    int duree,heures,minutes,secondes,hms[3];
    printf("Tapez une duree exprimee en secondes : ");
    scanf("%d",&duree);
    Conversion1(duree ,&heures ,&minutes ,&secondes);
    printf("%d secondes = %dh %dm %ds\n", duree, heures, minutes, secondes);
    Conversion2(duree,hms);
    printf("%d secondes = %dh %dm %ds\n", duree, hms[INDH], hms[INDM], hms[INDS]);
    return 0;
}
