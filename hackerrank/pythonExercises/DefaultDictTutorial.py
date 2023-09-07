# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

n, m = input().split()
n = int(n)
m = int(m)
a = []
for i in range(n):
    a.append(input())
b = []
for i in range(m):
    b.append(input())

# to eliminate duplicates in list 'b',
# while keeping the original ordering:
#b = list(dict.fromkeys(b))
#print(b)

d = defaultdict(list)
for x in b:
    if x in a: 
        if x not in d:
            frequency = a.count(x)
            prev = -1
            for i in range(frequency):
                d[x].append(str(a.index(x, prev+1) + 1))
                prev = a.index(x, prev+1)
    else:
        d[x].append(str(-1))
    print(' '.join(d[x]))
