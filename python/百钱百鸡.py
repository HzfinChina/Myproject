for x in range(1, 20):
    for y in range(0, (100 - 5 * x) // 3):
        z = 3 * (100 - 5 * x - 3 * y)
        if x + y + z == 100:
            print(f"公鸡{x}只,母鸡{y}只,小鸡{z}只")


