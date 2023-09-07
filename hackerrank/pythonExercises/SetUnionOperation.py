# Enter your code here. Read input from STDIN. Print output to STDOUT
n, english, b, french = int(input()), set(input().split()), int(input()), set(input().split())
print(len(english | french))
