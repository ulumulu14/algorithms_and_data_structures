#zadanie 4.5

def odwracanie(L, left, right):
    middle = int((left + right) / 2 + 1)
    j = right
    for i in range(left, middle):
        temp = L[i]
        L[i] = L[j]
        L[j] = temp
        j -= 1
