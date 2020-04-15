#Il faut avoir les implémentations des piles pour utiliser ce code (cf cours)
#Il faut aussi avoir EstMaj() (exo sur Moodle)

def designe_un_majoritaire(liste) :
    #partie initialisation
    pile = creer_pile_vide()
    pileW = creer_pile_vide()
    for elem in liste :
        empiler(pile, elem)

    #partie traitement de la collection
    while not pile_vide(pile) :
        if pile_vide(pileW) or sommet(pile) == sommet(pileW) :
            empiler(pileW, depiler(pile))
        else:
            val1 = depiler(pile)
            val2 = depiler(pileW)

    if pile_vide(pileW) or EstMaj(sommet(pileW), liste) :
        return None
    else:
        return sommet(pileW)