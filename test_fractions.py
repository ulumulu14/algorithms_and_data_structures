#test_fracions

import unittest
import fractions

class TestFractions(unittest.TestCase):

    def setUp(self):
        self.zero = [0, 1]

    def test_add_frac(self):
        self.assertEqual(fractions.add_frac([1, 2], [1, 3]), [5, 6])

    def test_sub_frac(self):
        self.assertEqual(fractions.sub_frac([3, 14], [5, 6]), [-13, 21])

    def test_mul_frac(self):
        self.assertEqual(fractions.mul_frac([1, 4], [3, 2]), [3, 8])

    def test_div_frac(self):
        self.assertEqual(fractions.div_frac([3, 8], [1, 2]), [3, 4])

    def test_is_positive(self):
        self.assertTrue(fractions.is_positive([1, 2]))
        self.assertFalse(fractions.is_positive([-1, 2]))

    def test_is_zero(self):
        self.assertTrue(fractions.is_zero([0, 0]))
        self.assertFalse(fractions.is_zero([-1, 2]))                         

    def test_cmp_frac(self):
        self.assertEqual(fractions.cmp_frac([3, 14], [3, 14]), 0)
        self.assertEqual(fractions.cmp_frac([-3, 14], [3, 15]), -1)
        self.assertEqual(fractions.cmp_frac([4, 14], [3, 14]), 1)

    def test_frac2float(self):
        self.assertEqual(fractions.frac2float([7, 3]), 2.3333333333333335)
        
    def tearDown(self):
        self.zero = None

if __name__ == '__main__':
    unittest.main()
