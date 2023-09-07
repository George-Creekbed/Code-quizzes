# Enter your code here. Read input from STDIN. Print output to STDOUT
N, X = map(int, input().split())
subject = []
for i in range(X):
    subject.append(list(map(float, input().split())))
for i in range(N):
    print(f'{sum(list(zip(*subject))[i]) / X:.1f}')
    
if __name__ == "__main__":
    import sys
