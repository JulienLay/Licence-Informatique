#include <stdio.h>

#define TAILLE_MAX 1024

// Ce progamme sert à afficher le contenu du fichier au format "PGM-ASCII"
// Utiliser la commande : ./nom_de_l'executable < mon_image.pgm

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

    for(int i = 0; i < nbLigMax; i++) // ok
    {
        for(int j = 0; j < nbColsMax; j++)
        {
            printf("%hhu ", tableau[i][j]);
        }
        printf("\n");
    }

    return 0;
}
