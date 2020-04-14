
# creer_file: retourne une file vide
def creer_file_vide():
  return []
  
# file_vide: retourne True si la file une_file est vide
def file_vide(une_file) :
  return nombre_elements(une_file) == 0
  
# nombre d'elements dans la file
def nombre_elements(une_file):
  return len(une_file)
            
# inserer: ajoute une_valeur en queue/fin de la file une_file
def inserer(une_file, une_valeur):
  une_file.append(une_valeur)
   
# extraire: supprime et retourne la valeur en tête de la file une_file. 
# Une exception est déclenchée si la file est vide
def extraire(une_file):
  assert not file_vide(une_file), "extraire interdit sur une file vide"
  valeur_en_tete = une_file[0]
  del une_file[0]
  return valeur_en_tete

# affiche à l'écran le contenu de la file une_file, en commençant 
# à partir de la premiere valeur en tete.               
def afficher(une_file):  
  print(une_file)         

def test():
  file=creer_file_vide()

  for i in range(1,11):
    inserer(file, i)
    
  print('taile de la file apres remplissage =', nombre_elements(file))
  afficher(file)
  
  print("vider la file")
  i=1
  while not file_vide(file):
    val = extraire(file)
    print('i =', i, ' val=', val, 'nouvelle taille =', nombre_elements(file))
    i += 1
  # declencher une exception pour un extraire en trop
  print('declencher une exception pour un extraire en trop')
  val = extraire(file)
 
if __name__ == "__main__":
  test()
