if __name__ == '__main__':
    n = int(raw_input())
    integer_list = map(int, raw_input().split())
    my_tuple = tuple(integer_list)
    print(hash(my_tuple))#.__hash__())
