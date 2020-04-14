def EstMaj(x, Linit):
  copiePile = creer_pile_vide()
  pileW = creer_pile_vide()

  for i in Linit:
    empiler(copiePile,i)

  valeur = depiler(copiePile)
  empiler(pileW, valeur)

  while not est_vide(copiePile):
      valeur = depiler(copiePile)
      if valeur == pileW[0]:
        empiler(pileW,valeur)
      else:
        depiler(pileW,pileW[0])

  if nombre_elements(pileW) > len(Linit)//2:
    if pileW[0] == x :
      return True

  return False