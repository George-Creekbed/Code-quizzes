def average(array):
    my_set = set(array)
    return str(f'{sum(my_set, 0) / len(my_set):.3f}')

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
