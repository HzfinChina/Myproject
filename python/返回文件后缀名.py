def get_suffix(filename):
    pos = filename.rfind('.')
    suffix = filename[pos+1:] if pos != 0 else ""
    return suffix
print(get_suffix("ab.py"))
