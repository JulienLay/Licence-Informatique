#Il faut avoir EstMaj() (exo sur Moodle)

def MajLOpt(listeInit) :
    liste = listeInit[:]

    if len(liste) > 1 :
        i = 0
        while i < len(liste) - 1 :
            if liste[i] == liste[i+1] :
                i += 1
            else:
                del liste[i]
                del liste[i]
            if i > 0 :
                i -= 1

    if len(liste) > 0 and EstMaj(liste[0], listeInit) :
        return liste[0]
    return None
