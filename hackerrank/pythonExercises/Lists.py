if __name__ == '__main__':
    N = int(input())
    my_list = []
    for i in range(N):
        line = input().split()
        line1 = [int(line[i]) for i in range(1, len(line))]
        line = [line[0]]
        line.extend(line1)
        if line[0] == 'insert':
            my_list.insert(line[1], line[2])
        elif line[0] == 'print':
            print(my_list)
        elif line[0] == 'remove':
            my_list.remove(line[1])
        elif line[0] == 'append':
            my_list.append(line[1])
        elif line[0] == 'sort':
            my_list.sort()
        elif line[0] == 'pop':
            my_list.pop()
        elif line[0] == 'reverse':
            my_list.reverse()
        else:
            print('Command not accepted.')
