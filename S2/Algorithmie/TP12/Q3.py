def EstMaj(x, Linit):
    L = Linit
    n = len(L)
    for i in range(n):
      if L[i] != L[i+1]:
        del L[i]
        del L[i+1]

    if len(L) != 0:
      majorant = L[0]
      nboc = 0
      for i in Linit:
        if i == L[0]:
          nboc += 1
          if nboc > n//2:
            return True

    return False