#zadanie 5.2

import math

def simplify(frac):
    gcd = math.gcd(frac[0], frac[1])
    frac = [int(frac[0] / gcd), int(frac[1] / gcd)]
    
    return frac

def add_frac(frac1, frac2): #pomnozyc mianowniki przez siebie i liczniki odpowiednio
    rtrn = [frac1[0] * frac2[1] + frac2[0] * frac1[1], frac1[1] * frac2[1]]
    return simplify(rtrn)
    
def sub_frac(frac1, frac2): #to samo
    rtrn = [frac1[0] * frac2[1] - frac2[0] * frac1[1], frac1[1] * frac2[1]]
    return simplify(rtrn)

def mul_frac(frac1, frac2):
    rtrn = [frac1[0] * frac2[0], frac1[1] * frac2[1]]
    
    return simplify(rtrn)

def div_frac(frac1, frac2):
    rtrn = [frac1[0] * frac2[1], frac1[1] * frac2[0]]

    return simplify(rtrn)
    
def is_positive(frac):
    if frac[0] * frac[1] < 0:
        return False
    else:
        return True
    
def is_zero(frac):
    if frac[0] == 0:
        return True
    else:
        return False
    
def cmp_frac(frac1, frac2):
    licznik1 = frac1[0] * frac2[1]
    licznik2 = frac1[1] * frac2[0]

    if licznik1 > licznik2:
        return 1
    elif licznik1 < licznik2:
        return -1
    else:
        return 0

def frac2float(frac):
    return float(frac[0]) / float(frac[1])
