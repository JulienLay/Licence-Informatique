#include <stdio.h>

#define TAILLE_MAX 1024

// Ce progamme sert à créer l'image retourné dans le dossier de travail
// Utiliser la commande : ./nom_de_l'executable < mon_image.pgm > mon_image_retourne.pgm

int main() {
    char charControle[3]; // SIGNATURE
    int nbColsMax;
    int nbLigMax;
    unsigned char MaxNvxGris;
    unsigned char tableau[TAILLE_MAX][TAILLE_MAX];

    scanf("%2s", charControle); //oook
    scanf("%d", &nbColsMax); //ok
    scanf("%d", &nbLigMax);// ok
    scanf("%hhu", &MaxNvxGris); // ok

    for(int i = 0; i < nbLigMax; i++)  //OK
    {
        for(int j = 0; j < nbColsMax; j++)
        {
            scanf("%hhu", &tableau[i][j]);
        }
    }

    printf("%s\n", charControle); //ok
    printf("%d %d\n", nbColsMax, nbLigMax); //ok
    printf("%hhu\n", MaxNvxGris);//ok

    for(int i = 0; i < nbColsMax; i++)
    {
        for(int j = 0; j < nbLigMax; j++)
        {
            printf("%hhu ", tableau[j][nbColsMax-i]);
        }
        printf("\n");
    }

    return 0;
}
