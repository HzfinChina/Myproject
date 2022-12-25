def add(a,b):
    print(__name__)
    return a + b

def times(a, b):
    print(__name__)
    return a * b 

def calc(a,b, func):
    print(func(a,b))

calc(2,3,times)

