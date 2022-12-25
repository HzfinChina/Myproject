#CRAPS赌博游戏
from random import randint

def roll_dice(n = 2):
    total = 0
    for _ in range(n):
        total += randint(1,6)
    return total

#可变参数
def add(*args):
    sum = 0
    for num in args:
        sum += num 
    return sum 
print(add(2,33,4,1))

