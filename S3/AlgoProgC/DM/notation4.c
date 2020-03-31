#include "sudoku.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>

// list of Sudoku grids with interesting bruteforce solutions
const int interesting_bruteforce[] = {0, 1, 2, 5, 7, 9, 10, 13, 15, 17};


T_sudoku chargerSudokuComplet(FILE* f, int n){
  int i,j,k, gridNb;
  T_sudoku s;

  gridNb = -1;
  // modified to find a grid with its identifier (not optimized)
  while(gridNb != n && !feof(f)) {
    fscanf(f," Sudoku: %d ", &gridNb);
    for(i=0;i<81;i++){
      fscanf(f," Case: %d, val: %d, n_candidats: %d, candidats: ",&j,&((s.grille[i]).val),&((s.grille[i]).n_candidats));
      for(k=0;k<9;k++){
        fscanf(f,"%d ",&((s.grille[i]).candidats[k]));
      }
    }
  }

  if(gridNb != n) {
    fprintf(stderr, "\n[ERROR] Unable to find grid %d in the solution files for bruteforce!\n", n);
    exit(1);
  }
  return s;
}

/*
 * Utilise pour comparer les solution (y compris intermediaires) de reference avec
 * les solutions des etudiants : renvoie 81 ssi les deux sudokus sont identiques.
 * NOTE version modifiée pour le bruteforce, qui ignore les candidats restants.
 */
int comparerSudokusBruteForce(T_sudoku* s1, T_sudoku* s2){
  int i,j;
  for(i=0;i<81;i++){
    if((s1->grille[i]).val != (s2->grille[i]).val){
      printf("\nErreur de valeur\n");
      return i;
    }
  }
  return 81;
}

int main() {
  int note = 0;
  int note_locale = 0;
  FILE *f, *f1;

  printf(
      "\n==================================================================\n");
  printf("Brute force\n");

  printf("Cela peut prendre du temps (quelques minutes) suivant votre algorithme.\n");
  fflush(stdout);

  f = fopen("sols/solFBrute.txt", "r");
  T_sudoku sudokuSol, sudokuEtudiant[100];
  int i, j, test, change = 1;
  int nbInteresting = sizeof(interesting_bruteforce)/sizeof(int);

  // look only at "interesting" solutions
  for (i = 0; i < nbInteresting; i++) {
    int n = interesting_bruteforce[i];

    change = 1;
    for (j = 0; j < 81; j++) {
      sudokuEtudiant[n].grille[j].val = tests[n][j];
    }
    initialiserSudoku(&(sudokuEtudiant[n]));
    // try to find and load the good grid
    sudokuSol = chargerSudokuComplet(f, n);
    R1_sudoku(&(sudokuEtudiant[n]));
    while (change) {
      change = 0;
      change += R2_sudoku(&(sudokuEtudiant[n]));
      change += R1_sudoku(&(sudokuEtudiant[n]));
      change += R3_sudoku(&(sudokuEtudiant[n]));
      change += R1_sudoku(&(sudokuEtudiant[n]));
    }

    printf("Application de la force brute sur la grille %d (%d/%d)...", n, i, nbInteresting);
    fflush(stdout);
    bruteForce(&(sudokuEtudiant[n]));
    printf("Done!\n");
    fflush(stdout);

    // XXX lower the comparison requirements
    test = comparerSudokusBruteForce(&(sudokuEtudiant[n]), &sudokuSol);
    if (test == 81) {
      note_locale += 1;
    } else {
      printf("\nErreur sur le sudoku : %d, case : %d", n, test);
    }
  }
  printf("\n\nTotal: %d/10\n", note_locale);
  note += note_locale;
  fclose(f);
  fprintf(stderr, "%d", note);
  return 0;
}
