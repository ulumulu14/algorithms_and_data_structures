#zadanie 8.4
import math

def heron(a, b, c):
    if (a + b > c) and (a + c > b) and (b + c > a):
        p = (a + b + c) * 0.5
        return math.sqrt(p * (p - a) * (p - b) * (p - c))
    else:
        try:
            raise ValueError("To nie jest trojkat!")
        except ValueError as err:
            print(err)
