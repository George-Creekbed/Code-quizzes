n = int(input())
s = set(map(int, input().split()))
N = int(input())
for i in range(N):
    command = input().split()
    if str(command[0]) == 'pop':
        s.pop()
    elif str(command[0]) == 'remove':
        s.remove(int(command[1]))
    elif str(command[0]) == 'discard':
        s.discard(int(command[1]))
    else:
        raise NameError("not a command")
print(sum(s))
