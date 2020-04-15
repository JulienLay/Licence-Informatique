def FBGL(liste):
    taille = len(liste)
    trouve = False
    i=0

    while i < taille and not trouve :
        nboc = 0
        j = i
        while j < taille and not trouve :
            if liste[i] == liste[j] :
                nboc += 1
                if nboc > taille // 2 :
                    trouve = True
            j += 1
        i+=1
    if trouve:
        return liste[j-1]
    else:
        return None