#include <stdio.h>

int main(void)
{
  int NbLettres=0,NbVoyelles=0,Erreur=0;
  char Caractere;
  
  printf("Tapez un texte non accentue, termine par un # :\n");
  scanf("%c",&Caractere);
  while (!Erreur && Caractere!='#')
  {
    if (Caractere!=' ' && (Caractere<'a' || Caractere>'z'))
      Erreur=1;
    else
    {
      if (Caractere!=' ')
      {
        NbLettres++;
        if ((Caractere=='a')||
            (Caractere=='e')||
            (Caractere=='i')||
            (Caractere=='o')||
            (Caractere=='u')||
            (Caractere=='y'))
          NbVoyelles++;
      }
      scanf("%c",&Caractere);
    }
  }

  if (!Erreur)
    printf("Il y a %d lettres et %d voyelles.\n",NbLettres,NbVoyelles);
  else
    printf("Erreur : le caractere %c de code %d n'est ni une minuscule "
           "non accentuee, ni un espace.\n",Caractere,Caractere);

  return 0;
}

