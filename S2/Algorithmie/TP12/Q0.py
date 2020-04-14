def FB(L):
    n = len(L)
    max = 0

    for i in L:
        nombre_occurence = 0
        for j in L:
            if i == j:
                nombre_occurence = nombre_occurence + 1

        if max < nombre_occurence:
            max = nombre_occurence
            majorant = i
  
    if max > n//2:
        return majorant
    else:
        return None