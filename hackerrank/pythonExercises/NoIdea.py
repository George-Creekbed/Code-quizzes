lengths = tuple(map(int, input().split()))
my_array = list(map(int, input().split()))
set_A = set(map(int, input().split()))
set_B = set(map(int, input().split()))
my_happiness = 0
for i in range(lengths[0]):
    if my_array[i] in set_A:
        my_happiness += 1 
    if my_array[i] in set_B:
        my_happiness -= 1
print(my_happiness)
