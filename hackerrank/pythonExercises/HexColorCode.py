# Enter your code here. Read input from STDIN. Print output to STDOUT
#STRING SPLIT WITH MULTIPLE DELIMITERS WITHOUT USING IMPORT RE !!!
import fileinput
import string

we_are_in = False
for line in fileinput.input():
    if line.count('{\n') > 0:
        we_are_in = True
    elif line.count('}\n') > 0:
        we_are_in = False
    elif we_are_in:
        counter = line.count('#')
        line = line.replace(':', ';')
        line = line.replace(';', ',')
        line = line.replace('(', ',')
        line = line.replace(')', ',')
        line = line.replace('-', ',')
        line = line.replace(',', ' ')
        words = line.split()
        if counter > 0:
            for i in words:
                if i.startswith('#'):
                    i = i.strip('#;,:() ')
                    if (len(i) == 3 or len(i) == 6):
                        if all (j in string.hexdigits for j in i):
                            print('#' + i)
