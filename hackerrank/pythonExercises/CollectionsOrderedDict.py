# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import OrderedDict
N = int(input())
my_dict = OrderedDict()
for i in range(N):
    line = input().split()
    if ' '.join(line[0:-1]) in my_dict:
        my_dict[' '.join(line[0:-1])] += int(line[len(line)-1])
    else:
        my_dict[' '.join(line[0:-1])] = int(line[len(line)-1])
pairs = [(k, v) for k, v in my_dict.items()]
for x in pairs:
    print(*x)
