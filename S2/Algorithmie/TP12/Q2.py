def MajL(Linit):
    L, n = Linit, len(L)

    for i in L:
        nboc = 0
        for j in L:
            if i == j:
                nboc += 1
                del i
                if nboc > n//2 or len(L) <= n//2:
                    return i
    return None