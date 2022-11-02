from itertools import combinations
S, k = input().split()
k = int(k)
S = sorted(S)
comb_array = []
for q in range(1,k+1):
    comb_array.extend(combinations(S, q))
[print(''.join([str(i) for i in item])) for item in comb_array]
