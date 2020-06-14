#zadanie 12.2


def binarne_rek(L, left, right, y):
    if (right - left) > 0:
        k = int((left + right)/2)

        if y == L[k]:
            return k
        elif y < L[k]:
            return binarne_rek(L, left, k - 1, y)
        else:
            return binarne_rek(L, k + 1, right, y)

    return None



L = [0,1,2,3,4,4,5,6,7,8,9]
y = 5



print(binarne_rek(L, 0, 10, y))
