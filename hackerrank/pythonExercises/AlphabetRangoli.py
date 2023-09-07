def print_rangoli(size):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    my_str = alphabet[size-1]
    print(my_str.center(4*(size-1)+1, '-'))
    for i in range(size-1):
        my_str_rev = my_str[::-1]
        print((my_str + '-' + alphabet[size-2-i] + '-' + my_str_rev)\
            .center(4*(size-1)+1, '-')
        )
        my_str += '-' + alphabet[size-2-i]

    my_str = my_str[:-4]
    for i in reversed(range(size-1)):
        my_str_rev = my_str[::-1]
        print((my_str + '-' + alphabet[size-1-i] + '-' + my_str_rev)\
            .center(4*(size-1)+1, '-')
        )
        my_str = my_str[:-2]
 

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
