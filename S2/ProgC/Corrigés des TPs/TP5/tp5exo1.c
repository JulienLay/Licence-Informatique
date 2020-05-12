#include <stdio.h>

/* Affiche les éléments d'un tableau de int
 * Tab : tableau de int
 * NbElt : nombre d'éléments du tableau Tab
 */
void AfficherTab(int Tab[], int NbElt)
{
    for (int i = 0; i < NbElt; i++)
        printf("%d ", Tab[i]);
    printf("\n");
}

/* Recherche du plus petit element d'un tableau de int
 * Tab : tableau de int
 * NbElt : nombre d'elements du tableau Tab
 * Retour : min du tableau Tab
 */
int Min(int Tab[], int NbElt)
{
    int min = Tab[0];
    for (int i = 1; i < NbElt; i++)
        if (Tab[i] < min)
            min = Tab[i];
    return min;
}

/* Recherche du plus grand element d'un tableau de int
 * Tab : tableau de int
 * NbElt : nombre d'elements du tableau Tab
 * Retour : max du tableau Tab
 */
int Max(int Tab[], int NbElt)
{
    int max = Tab[0];
    for (int i = 1; i < NbElt; i++)
        if (Tab[i] > max)
            max = Tab[i];
    return max;
}

/* Recherche du plus petit et du plus grand elements d'un tableau de int
 * Tab : tableau de int
 * NbElt : nombre d'elements du tableau Tab
 * pMin : adresse ou doit etre stocke le plus petit element
 * pMax : adresse ou doit etre stocke le plus grand element
 */
void MinMax(int Tab[], int NbElt, int *pMin, int *pMax)
{
    *pMin = Min(Tab, NbElt);
    *pMax = Max(Tab, NbElt);
}

/* Supprime toutes les occurences d'une valeur d'un tableau de int
 * Tab : tableau de int
 * pNbElt : adresse où est stocké le nombre d'éléments du tableau Tab
 * Val : valeur à supprimer
 * Retour : le nombre d'éléments supprimés
 */
int SupprimerVal(int Tab[], int *pNbElt, int Val)
{
    int nbSupp = 0, i = 0;
    while (i < *pNbElt) {
        if (Tab[i] == Val) {
            for (int j=i; j < *pNbElt-1; j++)
                Tab[j] = Tab[j+1];
            nbSupp++;
            (*pNbElt)--;
        }
        else
            i++;
    }
    return nbSupp;
}

/* Fonction principale */
/* ******************* */
int main(void)
{
    int t[] = {2, 2, 8, 7, 3, 6, 5};
    int NbElt = 7;
    int Min, Max;

    AfficherTab(t, NbElt);

    MinMax(t, NbElt, &Min, &Max);
    printf("Min=%d, Max=%d\n", Min, Max);

    printf("Suppression du 2 (%d occurence(s))\n", SupprimerVal(t, &NbElt, 2));
    AfficherTab(t, NbElt);

    printf("Suppression du 5 (%d occurence(s))\n", SupprimerVal(t, &NbElt, 5));
    AfficherTab(t, NbElt);

    return 0;
}
