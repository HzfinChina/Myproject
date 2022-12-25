x = float(input("请输入x"))
if x > 1:
    y = 3 * x - 5
elif x < -1:
    y = 5 * x + 3
else:
    y = x + 2
print("%.4f"%y)
