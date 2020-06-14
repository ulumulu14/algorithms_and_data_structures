#zadanie 8.3
import random

def calc_pi(n=100):
    """Obliczanie liczby pi metodą Monte Carlo.
    n oznacza liczbę losowanych punktów."""
    pkt_w_kole = 0
    for i in range(n):
        x = random.uniform(-1.0, 1.0)
        y = random.uniform(-1.0, 1.0)
        if x*x + y*y <= 1:
            pkt_w_kole = pkt_w_kole + 1

    pi = 4 * pkt_w_kole / n
        

    return pi

print(calc_pi())
