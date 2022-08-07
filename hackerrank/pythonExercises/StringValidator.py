if __name__ == '__main__':
    """ outputs whether the input string has:
    - any alphanum chars
    - any alpha chars
    - any digit chars
    - any lower case chars
    - any upper case chars """
    
    s = input()
    flag_alnum = False
    flag_alpha = False
    flag_digit = False
    flag_lower = False
    flag_upper = False

    for char in s:
        if char.isalnum():
            flag_alnum = True
            if char.isalpha():
                flag_alpha = True
                if char.islower():
                    flag_lower = True
                elif char.isupper():
                    flag_upper = True
            elif char.isdigit():
                flag_digit = True
            else:
                continue
        else:
            continue
    
    if flag_alnum:
        print('True')
    else:
        print('False')
    if flag_alpha:
        print('True')
    else:
        print('False')
    if flag_digit:
        print('True')
    else:
        print('False')
    if flag_lower:
        print('True')
    else:
        print('False') 
    if flag_upper:
        print('True')
    else:
        print('False')
