# Enter your code here. Read input from STDIN. Print output to STDOUT
M = int(input())
a = set(map(int, input().split()))
N = int(input())
b = set(map(int, input().split()))

#M,a,N,b = int(input()), set(map(int, input().split())), int(input()), set(map(int, input().split()))  #works!

sym_diff = sorted(list(a.difference(b).union(b.difference(a))))
print(*sym_diff, sep="\n")
