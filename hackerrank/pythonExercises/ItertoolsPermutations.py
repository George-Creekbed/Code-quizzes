# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import permutations

s, k = input().split()
k = int(k)

perms = list(permutations(sorted(s), k))
perms_str = [''.join(x) for x in perms]
for x in perms_str:
    print(x)
