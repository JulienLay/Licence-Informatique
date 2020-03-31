#include <stdio.h>

#define MAX_CHARA 80

int main()
{
    int i = 0;
    char caractere;
    char tableau[MAX_CHARA];

    //Lire le texte tapé et mettre les contraintes de ce qu'il faut taper
    printf("Veuillez taper un chaine de caractere (max 80 caracteres et n’est composé que de lettres minuscules non accentuées) : ");
    scanf("%c", &caractere);

    while((caractere != '\n' && (caractere >= 'a' && caractere <= 'z')) || caractere == ' ')
    {
        tableau[i]=caractere;
        i++;
        scanf("%c", &caractere);
    }

    //Afficher la chaine de caractere et le nombre de caractere
    printf("La chaine de caractere que vous avez tapée est : ");

    for (int k = 0; k < i; k++)
    {
        printf("%c", tableau[k]);
    }

    printf("\nElle contient %d caracteres.", i);

    printf("\n\n");

    //Afficher la chaine de caractere inversée
    printf("Chaine de caractère(s) inversée : ");

    for (int l = i-1; l >= 0; l--)
    {
        printf("%c", tableau[l]);
    }

    printf("\n\n");

    //Afficher si la chaine de caractere est palindrome ou pas
    int x = i-1;
    int w = 0;
    while(w<x)
    {
      if(tableau[w] == ' ')
      {
        w++;
      }
      if(tableau[x] == ' ')
      {
        x--;
      }

      if (tableau[w] != tableau[x])
      {
          printf("Pas palindrome.\n");
          return 0;
      }

      w++;
      x--;
    }

    printf("Palindrome.\n");

    return 0;
}
