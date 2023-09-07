from collections import namedtuple
N, data = int(input()), namedtuple('data', input().split())
students = [data(*tuple(input().split())) for i in range(N)]
print(f'{sum(int(x.MARKS) for x in students) / N:.2f}')
