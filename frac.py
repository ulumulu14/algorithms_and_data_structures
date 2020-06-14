#zadanie 6.5

import math

class Frac:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        if(self.y == 1):
            return str(self.x)
        else:
            return '(' + str(self.x) + '/' + str(self.y) + ')'# zwraca "x/y" lub "x" dla y=1

    def __repr__(self):
        return "Frac(" + str(self.x) + ", " + str(self.y) + ')'# zwraca "Frac(x, y)"

    def __add__(self, other):
        rtrn = Frac(self.x * other.y + other.x * self.y, self.y * other.y)
        return Frac.simplify(rtrn)# frac1 + frac2

    def __sub__(self, other):
        rtrn = Frac(self.x * other.y - other.x * self.y, self.y * other.y)
        return Frac.simplify(rtrn)# frac1 - frac2

    def __mul__(self, other):
        rtrn = Frac(self.x * other.x, self.y * other.y)
        return Frac.simplify(rtrn) # frac1 * frac2

    def __truediv__(self, other):
        rtrn = Frac(self.x * other.y, self.y * other.x)
        return rtrn# frac1 / frac2

    # operatory jednoargumentowe
    def __pos__(self):
        # +frac = (+1)*frac
        return self

    def __neg__(self):  # -frac = (-1)*frac
        return Frac(-self.x, self.y)

    def __invert__(self):  # odwrotnosc: ~frac
        return Frac(self.y, self.x)

    def __cmp__(self, other):
        licznik1 = self.x * other.y
        licznik2 = self.y * other.x
        
        if licznik1 > licznik2:
            return 1
        elif licznik1 < licznik2:
            return -1
        else:
            return 0
            
    def __float__(self):
        return float(self.x) / float(self.y)# float(frac)

    def simplify(self):
        gcd = math.gcd(self.x, self.y)
        rtrn = Frac(int(self.x / gcd), int(self.y / gcd))
    
        return rtrn
    
    def __eq__(self, other):
        f1 = Frac.simplify(self)
        f2 = Frac.simplify(other)
        return f1.x == f2.x and f1.y == f2.y
    
    def __ne__(self, other):
        f1 = Frac.simplify(self)
        f2 = Frac.simplify(other)
        return not self == other

#test_frac
import unittest

class TestFraction(unittest.TestCase):

    def SetUp(self):
        self.f = Frac(0,1)

    def test_print(self):
        self.assertEqual(str(Frac(1, 2)), "(1/2)")
        self.assertEqual(repr(Frac(1, 2)), "Frac(1, 2)")

    def test_add(self):
        self.assertEqual(Frac(1, 2) + Frac(1, 3), Frac(5, 6))
    
    def test_sub(self):
        self.assertEqual(Frac(3, 14) - Frac(5, 6), Frac(-13, 21))

    def test_mul(self):
        self.assertEqual(Frac(1, 4) * Frac(3, 2), Frac(3, 8))

    def test_div(self):
        self.assertEqual(Frac(3, 8) / Frac(3, 2), Frac(1, 4))

    def test_pos(self):
        self.assertEqual(+Frac(1,2), Frac(1, 2))

    def test_neg(self):
        self.assertEqual(-Frac(1,2), Frac(-1,2))

    def test_invert(self):
        self.assertEqual(~Frac(1, 2), Frac(2, 1))

    def test_cmp(self):
        self.assertEqual(cmp(Frac(1, 2), Frac(1, 2)), 0)
        self.assertEqual(cmp(Frac(-1, 2), Frac(1, 2)), -1)
        self.assertEqual(cmp(Frac(1, 2), Frac(-1, 2)), 1)

    def test_float(self):
        self.assertAlmostEqual(float(Frac(7, 3)), 2.3333333)


if __name__ == '__main__':
    unittest.main()

