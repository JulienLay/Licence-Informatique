import math

# -----------------
# Q1
# -----------------

def Q1(liste) :
  LChamps = []

  for elem in liste :
    LChamps.append({'val' : elem, 'coul' : 'b', 'pere' : (-1, -1)})

  return LChamps

liste = [0, 1, 1, 1, 1, 1, 1, 0, 1]
print("liste :")
print('[')
print(0, 1, 1)
print(1, 1, 1)
print(1, 0, 1)
print(']')
print('\n')
LChamps = Q1(liste)

print("Q1 :")
print(LChamps)
print('\n')

# -----------------
# Q2
# -----------------

def initialiser_matrice(L,M) :
  assert int(math.sqrt(len(L))) == math.sqrt(len(L)), "erreur taille"

  n = int(math.sqrt(len(L)))

  for i in range(n) :
    x = []
    for j in range(n) :
      x.append(L[i*n+j])
    M.append(x)

  return M

def afficher_matrice_carre(M) :
  n = len(M)
  print("[")
  for i in range(n) :
    print(M[i], ",")
  print("]")

def Q2(LChamps):
  MG = []

  initialiser_matrice(LChamps,MG)
  print("Q2 :")
  afficher_matrice_carre(MG)
  return MG


MG = Q2(LChamps)
print('\n')

# -----------------
# Q3
# -----------------

# Les files
def creer_file_vide() :
  return []

def file_vide(un_file) :
  return nombre_elements(une_file) == 0

def nombre_elements(une_file) :
  return len(un_file)

def inserer(une_file, une_valeur) :
  une_file.append(une_valeur)

def extraire(une_file) :
  assert not file_vide(une_file), "extraire interdit sur une file vide"
  valeur_en_tete = une_file[0]
  del une_file[0]
  return valeur_en_tete

# Q3.a

def est_position_valide(matrice,ligne,colonne) :
  nb_lignes = len(matrice)
  nb_colonnes = len(matrice)

  return 0<=ligne<nb_lignes and 0<=colonne<nb_colonnes

def TraiterVoisins(f, MG, s) :

  if est_position_valide(MG,s[0],s[1]-1) and MG[s[0]][s[1]-1]['val'] == 1 :
    inserer(f,(s[0],s[1]-1))
    MG[s[0]][s[1]-1]['coul'] = "g"
    MG[s[0]][s[1]-1]['pere'] = (0, s[1] - (s[1]-1))

  if est_position_valide(MG,s[0],s[1]+1) and MG[s[0]][s[1]+1]['val'] == 1 :
    inserer(f,(s[0],s[1]+1))
    MG[s[0]][s[1]+1]['coul'] = "g"
    MG[s[0]][s[1]+1]['pere'] = (0, s[1] - (s[1]+1))

  if est_position_valide(MG,s[0]-1,s[1]) and MG[s[0]-1][s[1]]['val'] == 1 :
    inserer(f,(s[0]-1,s[1]))
    MG[s[0]-1][s[1]]['coul'] = "g"
    MG[s[0]-1][s[1]]['pere'] = (s[0] - (s[0]-1), 0)

  if est_position_valide(MG,s[0]+1,s[1]) and MG[s[0]+1][s[1]]['val'] == 1 :
    inserer(f,(s[0]+1,s[1]))
    MG[s[0]+1][s[1]]['coul'] = "g"
    MG[s[0]+1][s[1]]['pere'] = (s[0] - (s[0]+1), 0)

  print("Q3.a :")
  afficher_matrice_carre(MG)
  print('\n')

f = creer_file_vide()
s = (0, 1)
TraiterVoisins(f, MG, s)
print("file :", f)
print("point:", s)
print('\n')

# Q3.b

def PCourtChemin(MG,sd,sf) :
  f = creer_file_vide()
  inserer(f, sd)
  MG[sd[0]][sd[1]]['coul'] = "g"
  chemin = [sd]
  point_courant = sd

  # tant qu’on a pas rencontré le point d’arrivée et qu'il reste des points gris
  while point_courant != sf :
    tr = extraire(f)
    TraiterVoisins(f,MG,point_courant)
    MG[point_courant[0]][point_courant[1]]['coul'] = "n"

    chemin.append(tr)

  return chemin


# MG déjà initialisée plus haut dans le code
sd = (0,2)
sf = (2,2)
print(PCourtChemin(MG,sd,sf))

'''
def k_voisins(lig,col,matrice,k):
    #nb de lignes ?
    nblig = len(matrice)
    #nb de colonnes ? Comme c'est carré c'est identique
    nbcol = nblig # = len(matrice[0]) on sait matrice non vide

    #initialiser la liste des voisins à vide
    liste_voisins = []

    ligne_min = max(lig-k,0)
    ligne_max = min(lig+k+1,nblig)
    colonne_min = max(col-k,0)
    colonne_max = min(col+k+1,nbcol)

    for ligne in range(ligne_min,ligne_max) :
        for colonne in range(colonne_min,colonne_max) :
            liste_voisins.append((ligne,colonne))
    return liste_voisins

#attention on ne demande QUE la fonction. Ne pas faire input/print
'''