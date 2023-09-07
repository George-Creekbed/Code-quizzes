# Enter your code here. Read input from STDIN. Print output to STDOUT
X = int(input())
available = list(input().split()) 
available = list(int(x) for x in available)
N = int(input())

requests_list = []
for i in range(N):
    x, y = input().split()
    requests_list.append((int(x), int(y)))
    
output = 0
for x in requests_list:
    if x[0] in available:
        available.remove(x[0])
        output += x[1]
print(output)
