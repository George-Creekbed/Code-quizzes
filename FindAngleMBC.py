# Enter your code here. Read input from STDIN. Print output to STDOUT
from math import *

ab = int(input())
bc = int(input())

ac = hypot(ab, bc)
mc = ac / 2

angle_bca = asin(ab/ac)
mn = mc * sin(angle_bca)
nc = mc * cos(angle_bca)
bn = bc - nc

angle_mbc = round(degrees(atan(mn/bn)))
print(f'{angle_mbc:.0f}\xb0')
# print(str(angle_mbc) + '\xb0') #alternative
