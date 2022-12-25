a = int(input("请输入a"))
b = int(input("请输入b"))
def Gcd(a, b):
    if b == 0:
        return a
    else:
        return Gcd(b, a % b)
def Lcm(a, b):
    return a * b / Gcd(a, b)

print("a, b 最大公约数为：%d, 最小公倍数为%d" % (Gcd(a, b), Lcm(a, b)))


