def gcd(a : int, b:int) -> int:
    ''' a > b'''
    while b != 0 :
        a, b = b, a % b
    return a;

def lcm(a: int, b: int) -> int:
    return int(a * b / gcd(a, b))



