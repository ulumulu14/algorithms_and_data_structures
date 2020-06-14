#zadanie 4.4

def fibonacci(n):
    
    fn0 = 0
    fn1 = 1

    if n <= 1:
        return n
    
    for i in range(1, n):
        fn = fn1 + fn0
        fn0 = fn1
        fn1 = fn

    return fn
