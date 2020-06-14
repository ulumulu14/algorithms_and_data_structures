#zadanie 6.2
import math

class Point:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return '(' + str(self.x) + ',' + str(self.y) + ')'

    def __repr__(self):
        return 'Point(' + str(self.x) + ',' + str(self.y) + ')'

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        return not self == other

    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)
        
    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)
    
    def __mul__(self, other):
        return self.x * other.x + self.y * other.y

    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def length(self):
        return math.sqrt(math.pow(self.x, 2) + math.pow(self.y, 2))



#test_point    

import unittest

class TestPoint(unittest.TestCase):

    def SetUp(self):
        pass

    def test_print(self):
        self.assertEqual(str(Point(1,2)), "(1,2)")
        self.assertEqual(repr(Point(1,2)), "Point(1,2)")

    def test_eq(self):
        self.assertTrue(Point(1,2) == Point(1,2))
        self.assertFalse(Point(1,2) == Point(1,3))
        
    def test_ne(self):
        self.assertTrue(Point(1,2) != Point(1,3))
        self.assertFalse(Point(1,2) != Point(1,2))

    def test_add(self):
        self.assertEqual(Point(1,2) + Point(1,3), Point(2,5))

    def test_sub(self):
        self.assertEqual(Point(3,2) - Point(1,1), Point(2,1))

    def test_mul(self):
        self.assertEqual(Point(1,2) * Point(1,2), 5)

    def test_cross(self):
        self.assertEqual(Point.cross(Point(1,2), Point(1,3)), 1)

    def test_length(self):
        self.assertAlmostEqual(Point.length(Point(1,2)), 2.23606797749979)

    def TearDown(self):
        pass


if __name__ == '__main__':
    unittest.main()
