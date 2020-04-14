
# creer_pile: retourne une pile vide
def creer_pile_vide():
  return []
  
# pile_vide: retourne True si la pile une_pile est vide
def pile_vide(une_pile) :
  return nombre_elements(une_pile) == 0
  
# nombre d'elements dans la pile
def nombre_elements(une_pile):
  return len(une_pile)
            
# empiler: ajoute une_valeur en sommet de la pile une_pile
def empiler(une_pile, une_valeur):
  une_pile.insert(0, une_valeur)
   
# depiler: supprime et retourne la valeur en sommet de la pile une_pile. 
# Une exception est déclenchée si la pile est vide
def depiler(une_pile):
  assert not pile_vide(une_pile), "depiler interdit sur une pile vide"
  sommet = une_pile[0]
  del une_pile[0]
  return sommet

# affiche à l'écran le contenu de la pile une_pile, en commençant 
# à partir de la valeur en sommet.               
def afficher(une_pile):  
  print(une_pile)         

def test():
  pile=creer_pile_vide()

  for i in range(1, 11):
    empiler(pile, i)
    
  print("nombre d'element dans la pile = ", nombre_elements(pile))
  afficher(pile)
  
  print("vider la pile")

  i=1
  while not pile_vide(pile):
    val = depiler(pile)
    print('i =', i, ' val=', val, "nombre d'elements restant dans la pile = ", nombre_elements(pile))
    i += 1
    
  print("declencher une exception pour un depiler en trop")  
  val = depiler(pile)

if __name__ == "__main__":
  test()
