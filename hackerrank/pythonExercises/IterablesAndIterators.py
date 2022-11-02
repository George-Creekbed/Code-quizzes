# Enter your code here. Read input from STDIN. Print output to STDOUT
import itertools
N = int(input())
letters = list(itertools.filterfalse(lambda x: x.isspace(), input()))
# above, equal to letters = input().split() ...
K = int(input())
tot_combs = list(itertools.combinations(letters, K))
prob_a = []
for item in tot_combs:
#    for i in item:
#        if i == 'a':
#            prob_a.append(item)
#            break
# better:
    if 'a' in item:
		prob_a.append(item)
print(f'{len(prob_a) / len(tot_combs):.3f}')
#[print(item, end=" ") for item in letters]
#print('\n')
#[print(item, end=" ") for item in tot_combs]
#print('\n')
#[print(item, end=" ") for item in prob_a]
