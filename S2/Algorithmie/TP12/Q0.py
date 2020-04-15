def FB0(liste):
    taille = len(liste)
    nombre_max = 0

    for elem1 in liste :
        nboc = 0
        for elem2 in liste :
            if elem1 == elem2 :
                nboc += 1

        if nombre_max < nboc :
            nombre_max = nboc
            majorant = elem1

    if nombre_max > taille//2:
        return majorant
    else:
        return None