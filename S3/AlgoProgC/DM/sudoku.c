#include "sudoku.h"
/* Implanter les fonctions de sudoku.h ici */

/* Traduction indice/coordonnees */
T_coordonnees obtenirCoords(int indice){
T_coordonnees ca;
ca.ligne=indice/9;
ca.colonne=indice%9;
return ca;
}

int obtenirIndice(T_coordonnees coords){
return (9*coords.ligne+coords.colonne);
}


T_coordonnees debutRegion(int indiceRegion){
  T_coordonnees coord_region;
  coord_region.ligne = 3*(indiceRegion/3);
  coord_region.colonne = 3*(indiceRegion%3);
  return coord_region;
}

int indiceRegion(T_coordonnees coords){
 return (3*(coords.ligne/3)+(coords.colonne/3));
}

/* Lire une grille et initialiser un sudoku */
T_sudoku lireSudoku(char* chemin){
  T_sudoku s;
  int i=0;
  int car=0;
  FILE* fich=NULL;
  fich=fopen(chemin,"r");
  car=fgetc(fich);
  while(car!=EOF){
    if(car!=' ' && car!='\n'){
      (s.grille[i]).val=car-48;
      i++;
    }
    car=fgetc(fich);
  }

  fclose(fich);
  return s;
}




// initialiserSudoku prend un sudoku qui vient d'être lu (et dont certaines cases valent 0) et ajuste les valeurs de n_candidats et du tableau de candidat pour chaque case selon la valeur lue pour la case
void initialiserSudoku(T_sudoku* s){
  int can=0;
  for(int i=0;i<81;i++){
    if(s->grille[i].val==0){
      s->grille[i].n_candidats=9;
      can=1;
      for(int j=0;j<9;j++){
      (s->grille[i]).candidats[j]=can;
      can++;
      }
    }
    else{
      (s->grille[i]).n_candidats=0;
      for(int j=0;j<9;j++){
      (s->grille[i]).candidats[j]=0;
      }
    }
  }
}

/* Affichage de grilles */
void afficherSudoku(T_sudoku s){
 int indice_case=0;
  printf("\n");

  for(int i=0;i<9;i++){
  //  printf("i=%d ",indice_case);
    for(int j=0;j<9;j++){
      printf("%d",(s.grille[indice_case]).val);
      indice_case++;
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}

// /* Recherche et suppression de candidats dans une case */
int rechercherValeur(int val, T_case c)/* Renvoie l'indice de val dans le tableau de candidats de c. Si l'indice n'est pas present, renvoie c.n_candidats */
{
  for(int i=0;i<c.n_candidats;i++){
    if(c.candidats[i]==val){
      return i;
    }
  }
  return c.n_candidats;
}


void supprimerValeur(int ival, T_case* pc)/* ival est l'indice de la valeur a supprimer, on cosidere que la valeur a supprimer est presente dans les candidats de la case */
{
  if(ival!=pc->n_candidats){
    for(int i=ival;i<pc->n_candidats;i++){
      if(i==8){
        pc->candidats[i]=0;
      }
      else{
        pc->candidats[i]=pc->candidats[i+1];
      }
    }
    pc->n_candidats--;
  }
}
// /* Implementation des regles */

//----------------------------------------
//r1
int R1_case(T_case* pc) /* Applique R1 sur la case */
{
  if(pc->n_candidats==1){
    pc->val=pc->candidats[0];
    pc->candidats[0]=0;
    pc->n_candidats=0;
    return 1;
  }
  return 0;
}

int R1_sudoku(T_sudoku* ps) /* Applique R1 sur toutes les cases du sudoku, renvoie 1 si une modification a eu lieu, 0 sinon */
{
  T_coordonnees c_case, c_case_re;
  int i_re=0,val=0,li=0,col=0,mod=0;

  for(int i=0;i<81;i++){

    if(R1_case(&ps->grille[i])==1){
      mod=1;//une case à été modifiée
      val=ps->grille[i].val;
      c_case=obtenirCoords(i);
      li=c_case.ligne;
      col=c_case.colonne;
      for(int j_li=i-col;j_li<(i-col)+9;j_li++){//ligne à parcourir
        supprimerValeur(rechercherValeur(val,ps->grille[j_li]),&ps->grille[j_li]);
      }

      for(int j_col=col;j_col<=col+8*9;j_col=j_col+9){//colone à parcourir
        supprimerValeur(rechercherValeur(val,ps->grille[j_col]),&ps->grille[j_col]);
      }

      c_case=debutRegion(indiceRegion(obtenirCoords(i)));
      li=c_case.ligne;
      col=c_case.colonne;
      for(int j_li_re=li ; j_li_re<li+3 ; j_li_re++){//région à parcourir
        for(int j_col_re=col ; j_col_re<col+3 ; j_col_re++){
          c_case_re.ligne=j_li_re;
          c_case_re.colonne=j_col_re;
          i_re=obtenirIndice(c_case_re);
          supprimerValeur(rechercherValeur(val,ps->grille[i_re]),&ps->grille[i_re]);
        }
      }

    }
  }
  return mod;
}

//-------------------------------------
//r2
int R2_case(int i_case, T_sudoku* ps)/* Applique R2 sur la case. */
{
  int mod=0;
  int li=0,col=0,i_deb_li=0;
  if(ps->grille[i_case].n_candidats>0){//si in y a plus d'un candidat dans la case
    i_deb_li=i_case-(obtenirCoords(i_case).colonne);//indice de début de ligne parmis 81
    for(int i=i_deb_li;i<i_deb_li+9;i++){//pour la ligne
      if(ps->grille[i].val!=0 && ps->grille[i_case].n_candidats>0){//si une valeur a été attribuée
        int nb_can=0;
        nb_can=ps->grille[i].n_candidats;
        supprimerValeur(rechercherValeur(ps->grille[i].val,ps->grille[i_case]),&ps->grille[i_case]);
        if(nb_can!=ps->grille[i].n_candidats){
        mod=1;
        }
      }
    }
  }
  if(ps->grille[i_case].n_candidats>0){//si in y a plus d'un candidat dans la case
    for(int i=obtenirCoords(i_case).colonne;i<=obtenirCoords(i_case).colonne+8*9;i=i+9){//pour la colonne
      if(ps->grille[i].val!=0 && ps->grille[i_case].n_candidats>0){//si une valeur a été attribuée
        int nb_can=0;
        nb_can=ps->grille[i].n_candidats;
        supprimerValeur(rechercherValeur(ps->grille[i].val,ps->grille[i_case]),&ps->grille[i_case]);
        if(nb_can!=ps->grille[i].n_candidats){
        mod=1;
        }
      }
    }
  }
  if(ps->grille[i_case].n_candidats>0){//si in y a plus d'un candidat dans la case
    T_coordonnees c_case_re;
    c_case_re=debutRegion(indiceRegion(obtenirCoords(i_case)));
    li=c_case_re.ligne;
    col=c_case_re.colonne;
    for(int j_li_re=li ; j_li_re<li+3 ; j_li_re++){//région à parcourir
      for(int j_col_re=col ; j_col_re<col+3 ; j_col_re++){
        int i_re;
        c_case_re.ligne=j_li_re;
        c_case_re.colonne=j_col_re;
        i_re=obtenirIndice(c_case_re);
        if(ps->grille[i_re].val!=0 && ps->grille[i_case].n_candidats>0){//si une valeur a été attribuée
          int nb_can=0;
          nb_can=ps->grille[i_re].n_candidats;
          supprimerValeur(rechercherValeur(ps->grille[i_re].val,ps->grille[i_case]),&ps->grille[i_case]);
          if(nb_can!=ps->grille[i_re].n_candidats){
          mod=1;
          }
        }
      }
    }
  }
  return mod;
}

int R2_sudoku(T_sudoku* ps) /* Applique R2 sur toutes les cases du sudoku, renvoie 1 si une modification a eu lieu, 0 sinon */
{
  int mod=0;
  for(int i=0;i<81;i++){
    if(R2_case(i,ps)==1){
      mod=1;
    }
  }
  return mod;
}

//---------------------------------------
//r3

int R3_case(int i_case, T_sudoku* ps){ /* Applique R3 sur la case. */
  int mod=0, val_unique=1,li=0,col=0;

  for(int i=0;i<ps->grille[i_case].n_candidats;i++){ //on parcour les candidats de la case
    val_unique=1;
    T_coordonnees c_case;
    c_case=obtenirCoords(i);
    li=c_case.ligne;
    col=c_case.colonne;

    for(int j_li=i-col;j_li<(i-col)+9;j_li++){//ligne à parcourir
      if(j_li!=i_case){
        for(int j=0;j<ps->grille[j_li].n_candidats;j++){//on parcour les candidats de la case
          if(ps->grille[j_li].candidats[j]==ps->grille[i_case].candidats[i] && val_unique==1){
            val_unique=0;
          }
        }
      }
    }

    if(val_unique==1){//si la valeur est unique pour un groupement on l'attribu à la case
      ps->grille[i_case].val=ps->grille[i_case].candidats[i];
      for(int compteur=0;compteur<ps->grille[i_case].n_candidats;compteur++){
        ps->grille[i_case].candidats[compteur]=0;
      }
      ps->grille[i_case].n_candidats=0;
      mod=1;
    }

    if(val_unique==0){
    //  val_unique=1;

      for(int j_col=col;j_col<=col+8*9;j_col=j_col+9){//colone à parcourir
        if(j_col!=i_case){
          for(int j=0;j<ps->grille[j_col].n_candidats;j++){//on parcour les candidats de la case
            if(ps->grille[j_col].candidats[j]==ps->grille[i_case].candidats[i] && val_unique==1){
              val_unique=0;
            }
          }
        }
      }

      if(val_unique==1){//si la valeur est unique pour un groupement on l'attribu à la case
        ps->grille[i_case].val=ps->grille[i_case].candidats[i];
        for(int compteur=0;compteur<ps->grille[i_case].n_candidats;compteur++){
          ps->grille[i_case].candidats[compteur]=0;
        }
        ps->grille[i_case].n_candidats=0;
        mod=1;
      }
    }

    if(val_unique==0){
    //  val_unique=1;

      c_case=debutRegion(indiceRegion(obtenirCoords(i)));
      li=c_case.ligne;
      col=c_case.colonne;

      for(int j_li_re=li ; j_li_re<li+3 ; j_li_re++){//région à parcourir
        for(int j_col_re=col ; j_col_re<col+3 ; j_col_re++){
          int i_re=0;
          c_case.ligne=j_li_re;
          c_case.colonne=j_col_re;
          i_re=obtenirIndice(c_case);

          if(i_re!=i_case){
            for(int j=0;j<ps->grille[i_re].n_candidats;j++){//on parcour les candidats de la case
              if(ps->grille[i_re].candidats[j]==ps->grille[i_case].candidats[i] && val_unique==1){
                //si on trouve une autre case avec le meme candidat
                val_unique=0;
              }
            }
          }
        }
      }
      if(val_unique==1){//si la valeur est unique pour un groupement on l'attribu à la case
        ps->grille[i_case].val=ps->grille[i_case].candidats[i];
        for(int compteur=0;compteur<ps->grille[i_case].n_candidats;compteur++){
          ps->grille[i_case].candidats[compteur]=0;
        }
        ps->grille[i_case].n_candidats=0;
        mod=1;
      }
    }
  }
  return mod;
}

int R3_sudoku(T_sudoku* ps){ /* Applique R3 sur toutes les cases du sudoku, renvoie 1 si une modification a eu lieu, 0 sinon */

    T_coordonnees c_case, c_case_re;
    int i_re=0,val=0,li=0,col=0,mod=0;

    for(int i=0;i<81;i++){

      if(R3_case(i,ps)==1){
        mod=1;//une case à été modifiée
        val=ps->grille[i].val;
        c_case=obtenirCoords(i);
        li=c_case.ligne;
        col=c_case.colonne;
        for(int j_li=i-col;j_li<(i-col)+9;j_li++){//ligne à parcourir
          supprimerValeur(rechercherValeur(val,ps->grille[j_li]),&ps->grille[j_li]);
        }

        for(int j_col=col;j_col<=col+8*9;j_col=j_col+9){//colone à parcourir
          supprimerValeur(rechercherValeur(val,ps->grille[j_col]),&ps->grille[j_col]);
        }

        c_case=debutRegion(indiceRegion(obtenirCoords(i)));
        li=c_case.ligne;
        col=c_case.colonne;
        for(int j_li_re=li ; j_li_re<li+3 ; j_li_re++){//région à parcourir
          for(int j_col_re=col ; j_col_re<col+3 ; j_col_re++){
            c_case_re.ligne=j_li_re;
            c_case_re.colonne=j_col_re;
            i_re=obtenirIndice(c_case_re);
            supprimerValeur(rechercherValeur(val,ps->grille[i_re]),&ps->grille[i_re]);
          }
        }

      }
    }
    return mod;
  }

/* Bonus */
int bruteForce(T_sudoku* ps){
  T_sudoku s_init, s_test, s_i_moins_un;
  for(int i=0;i<81;i++){
    s_init.grille[i]=ps->grille[i];
  }
  for(int i=0;i<81;i++){
    s_test.grille[i]=ps->grille[i];
  }
  while(valide(ps)!=1){
    for(int i=0;i<81;i++){
      if(ps->grille[i].val==0){
        //on met un des candidats à val et si valide==0 on essaye avec un autre
        for(int i_can=0;i_can<ps->grille[i].n_candidats;i_can++){
          s_test.grille[i].val=ps->grille[i].candidats[i_can];

          if(verifResultat(s_init,s_test)==1){
            ps->grille[i].val=ps->grille[i].candidats[i_can];
            s_test.grille[i].val=s_test.grille[i].candidats[i_can];
            i_can=ps->grille[i].n_candidats;//on sort du for
          }

        }
      }
    }
    for(int i=0;i<81;i++){
      s_i_moins_un.grille[i]=ps->grille[i];
    }
    if(sudo_identique(ps,&s_i_moins_un)==1){
      return 0;
    }
  }
return 1;
}
//
// /* Verification du resultat */
int sudo_identique(T_sudoku* s1,T_sudoku* s2){//retourne 1 si les deux sudoku sont identiques sinon 0
  for(int i=0;i<81;i++){
    if(s1->grille[i].val!=s2->grille[i].val){
      return 0;
    }
  }
  return 1;
}

int valide(T_sudoku s){/* Renvoie 1 si la grille est complete et valide */
  for(int i=0;i<81;i++){
    if(s.grille[i].val!=0){//grille complete
    //lignes
      for(int i_li=i-obtenirCoords(i).colonne;i_li<i-obtenirCoords(i).colonne+9;i_li++){
        if(s.grille[i_li].val==s.grille[i].val){
          return 0;
        }
      }
      //colonnes
      for(int i_col=obtenirCoords(i).colonne;i_col<obtenirCoords(i).colonne+8*9;i_col=i_col+9){
        if(s.grille[i_col].val==s.grille[i].val){
          return 0;
        }
      }
      //région
      for(int i_li_re=debutRegion(indiceRegion(obtenirCoords(i))).ligne;i_li_re<debutRegion(indiceRegion(obtenirCoords(i))).ligne+3;i_li_re++){
        for(int i_col_re=debutRegion(indiceRegion(obtenirCoords(i))).colonne;i_col_re<debutRegion(indiceRegion(obtenirCoords(i))).colonne+3;i_col_re++){
          T_coordonnees c_case;
          c_case.ligne=i_li_re;
          c_case.colonne=i_col_re;
          if(s.grille[obtenirIndice(c_case)].val==s.grille[i].val){
            return 0;
          }
        }
      }
    }
    else{
      return 0;
    }
  }
  return 1;
}

int verifResultat(T_sudoku initialS,T_sudoku s){ /* Renvoie 1 si le sudoku est correct, et correspond bien au probleme initial */
  for(int i=0;i<81;i++){
    if(initialS.grille[i].val!=0 && initialS.grille[i].val!=s.grille[i].val){
      return 0;
    }
    for(int i_li=i-obtenirCoords(i).colonne;i_li<i-obtenirCoords(i).colonne+9;i_li++){
      if(s.grille[i_li].val==s.grille[i].val){
        return 0;
      }
    }
    //colonnes
    for(int i_col=obtenirCoords(i).colonne;i_col<obtenirCoords(i).colonne+8*9;i_col=i_col+9){
      if(s.grille[i_col].val==s.grille[i].val){
        return 0;
      }
    }
    //région
    for(int i_li_re=debutRegion(indiceRegion(obtenirCoords(i))).ligne;i_li_re<debutRegion(indiceRegion(obtenirCoords(i))).ligne+3;i_li_re++){
      for(int i_col_re=debutRegion(indiceRegion(obtenirCoords(i))).colonne;i_col_re<debutRegion(indiceRegion(obtenirCoords(i))).colonne+3;i_col_re++){
        T_coordonnees c_case;
        c_case.ligne=i_li_re;
        c_case.colonne=i_col_re;
        if(s.grille[obtenirIndice(c_case)].val==s.grille[i].val){
          return 0;
        }
      }
    }
  }
  return 1;
}

/* Resolution */
void resoudreSudoku(char* chemin){}
void resoudreSudokuCharge(int** ps,int nb){}

int main(){
  T_sudoku s;
  // int i=0;
  s=lireSudoku("test_sudo0.txt");
  initialiserSudoku(&s);
  afficherSudoku(s);
  printf("bruteforce = %d\n",bruteForce(&s));
  afficherSudoku(s);
  return 0;
}
