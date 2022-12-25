year = float(input("请输入年份"))
if year % 4 == 0 or year % 400 == 0:
    print("%d年是闰年"%year)
else:
    print("%d年不是闰年"%year)

