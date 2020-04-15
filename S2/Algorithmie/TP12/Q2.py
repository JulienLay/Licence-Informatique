def MajL(listeInit):
    liste = listeInit
    taille = len(liste)
    nboc = 0
    trouve = False

    while len(liste) != 0 and not trouve :
        nboc = 0
        cand = liste[0]
        liste_aux = []

        while len(liste) != 0 and not trouve :
            if cand == liste[0] :
                nboc += 1
                if nboc > taille // 2 :
                    trouve = True

                else:
                    liste_aux.append(liste[0])
                del liste[0]
            liste = liste_aux

        if trouve :
            return cand
        else:
            return None