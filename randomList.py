#zadanie 11.1
import random

def randomList(N):
    return random.sample(range(N), N)

def almostAscendingSorted(N):
    L = []

    for i in range(N):
        L.append(i)

    for i in range(int(N/10)):
        j = random.randint(0, N - 1)
        k = random.randint(0, N - 1)
        temp = L[j]
        L[j] = L[k]
        L[k] = temp

    return L

def almostDescendingSorted(N):
    L = almostAscendingSorted(N)
    L.reverse()
    return L

def gauss(N):
    L = []

    for i in range(N - 1):
        L.append(random.gauss(100, 15))

    return L

def repetitiveRandom(N, k):
    L = []
    
    if k >= N:
        raise ValueError("Zbior k ma zbyt wiele elementow")

    for i in range(N):
        L.append(random.randint(0, k))

    return L
