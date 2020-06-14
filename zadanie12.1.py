#zadanie 12.1

import random


def linearSearch(n, k):
    L = []
    rtrn = []

    for i in range(n):
        L.append(random.randint(0, k))

    
    y = random.randint(0, k)
    
    for i in range(len(L)):
        if L[i] == y:
            rtrn.append(i)
    
    if rtrn:
        return rtrn
    else:
        return None




print(linearSearch(100,100))
