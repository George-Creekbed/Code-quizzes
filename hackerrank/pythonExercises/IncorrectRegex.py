import re
T = int(input())
for i in range(T):
    try:
        re.compile(input())
        print("True")
    except re.error:
        print("False")
