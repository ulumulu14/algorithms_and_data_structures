#zadanie 11.5
#Sortowanie pozycyjne to algorytm sortujący stabilnie ciągi wartości względem
#kolejnych wartości od najmniej znaczących do najbardziej znaczących. Złożoność
#obliczeniowa to O(d(n+k)), gdzie k to liczba różnych cyfr, a d liczba cyfr w
#kluczach. Nie wykonuje on żadncyh operacji porównywania na danych wejściowych.

import asyncio
import math

def intLength(n):
    if n > 0:
        digits = int(math.log10(n))+1
    elif n == 0:
        digits = 1
    else:
        digits = int(math.log10(-n))+2

    return digits

def LSDradixSort(L, maxLen):
    bins = []

    for i in range(10):
        bins.append(asyncio.Queue())
    
    for i in range(maxLen):
        for j in range(len(L)):
            digits = intLength(L[j])
            bin = 0
            
            if i <= digits:
                number = L[j]
                
                for k in range(i + 1):
                    bin = number % 10
                    number = int(number / 10)

            bins[int(bin)].put_nowait(L[j])

        L = []
        for j in range(10):
            while not bins[j].empty():
                L.append(bins[j].get_nowait())

    return L

L = [1,20,3, 56, 34, 66,3 ,5 ,0]
print(LSDradixSort(L,2))

