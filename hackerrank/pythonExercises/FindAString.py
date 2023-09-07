def count_substring(string, sub_string):
    ret = 0
    for i in range(0, len(string) - len(sub_string) + 1):
        ret += string.count(sub_string, i, i+len(sub_string))
    return ret

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)
