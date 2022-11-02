from itertools import combinations_with_replacement
S, k = input().split()
k = int(k)
S = sorted(S)
comb_array = combinations_with_replacement(S,k)
[print(''.join([str(i) for i in item])) for item in comb_array]
