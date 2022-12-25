import random 
import string
ALL_CHARS = string.ascii_letters + string.digits
def generate(code_len = 20):
    strlen = len(ALL_CHARS)
    code_list = list()
    for _ in range(code_len):
        code_list.append(ALL_CHARS[random.randint(0,strlen-1)])
    return ''.join(code_list)

