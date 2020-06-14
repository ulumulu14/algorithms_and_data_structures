#zadanie 8.1

def solvel(a, b, c):
    if a == 0 and b != 0:
        x = 'r'
        y = str(-c/b)
        print('(' + x + ', ' + y + ')')
    elif a != 0 and b == 0:
        x = str(-c/a)
        y = 'r'
        print('(' + x + ', ' + y + ')')
    else:
        x = 'r'
        y = str(-a/b) + " * r "
        if -c/b < 0:
            y += '- ' + str(-c/b)
        else:
            y += '+ ' + str(-c/b)
        st = '(' + x + ', ' + y + ')'
        
        print(st)
