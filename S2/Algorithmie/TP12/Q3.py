def EstMaj(x, Linit):
    est_maj, indice, compteur = False, 0, 0

    while indice < len(liste) and not est_maj :
        if x == liste[indice] :
            compteur += 1
        if compteur > len(liste) // 2 :
            est_maj = True
        indice += 1
    return est_maj