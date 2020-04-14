def FBG(L):
    n = len(L)

    for i in L:
        nboc = 0
        for j in L:
            if i == j:
                nboc += 1
                if nboc > n//2:
                    return i
    return None