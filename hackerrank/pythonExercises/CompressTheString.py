# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import groupby
S = input()
output = []
for k, g in groupby(S):
    output.append(tuple([len(list(g)), int(k)]))
print(*output)
