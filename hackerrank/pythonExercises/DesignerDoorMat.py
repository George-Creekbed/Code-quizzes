# Enter your code here. Read input from STDIN. Print output to STDOUT
if __name__ == '__main__':
    N, M = input().split()
    N, M = int(N), int(M)     

motif = '.|.'
for i in range(N//2):
    print((motif + 2 * i * motif).center(M, '-'))

print('WELCOME'.center(M, '-'))

for i in reversed(range(N//2)):
    print((motif + 2 * i * motif).center(M, '-'))
