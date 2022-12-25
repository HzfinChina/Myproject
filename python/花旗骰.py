import random
import time
random.seed(time.time())
dice_1 = random.randint(1,6)
dice_2 = random.randint(1,6)
i = 1#次数
print(f"第{i}次，dice_1:{dice_1}, dice_2:{dice_2}")
if dice_1 + dice_2 == 7 or dice_1 + dice_2 == 9:
    print("Player win")
elif dice_1 + dice_2 == 2 or dice_1 + dice_2 == 3 or dice_1 + dice_2 == 12:
    print("Banker win")
else:
    firstnum = dice_1 + dice_2
    while True:
        i += 1
        dice_1 = random.randint(1,6)
        dice_2 = random.randint(1,6)
        print(f"第{i}次，dice_1:{dice_1}, dice_2:{dice_2}")
        if dice_1 + dice_2 == firstnum:
            print("Player Win")
            break
        elif dice_1 + dice_2 == 7:
            print("Banker win")
            break
        else:
            continue
        

