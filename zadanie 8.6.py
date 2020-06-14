#zadanie 8.6
from collections import defaultdict

def P(i, j):
    d = defaultdict(dict)
    
    d[0][0] = 0.5

    for i in range(1, i + i):
        d[i][0] = 0.0
    for j in range(1, j + 1):
        d[0][j] = 1.0
    for i in range(1, i + 1):
        for j in range(1, j + 1):
            d[i][j] = 0.5 * (d[i - 1][j] + d[i][j - 1])

    return d[i][j]
