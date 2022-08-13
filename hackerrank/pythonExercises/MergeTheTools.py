def merge_the_tools(string, k):
    # your code goes here
    sub_list = [string[i:i+k] \
        for i in range(0, len(string), k)]

    for substring in sub_list:
        temp = ''.join(dict.fromkeys(substring))
        print(temp)

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
