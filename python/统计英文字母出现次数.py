sentence = input("请输入一段话")
cout = dict()
for ch in sentence:
    if 'A' <= ch <= 'Z' or 'a' <= ch <= 'z':
        cout[ch] = cout.get(ch, 0) + 1
for key, value in cout.items():
    print(f"字母:{key},次数:{value}")
