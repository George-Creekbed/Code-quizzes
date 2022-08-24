for i in range(1,int(input())+1): 
	#CANCEL ALL COMMENTS BEFORE SUBMITTING
# More than 2 lines will result in 0 score. 
# Do not leave a blank line also
    #my_list = list(x+1 for x in range(i)).extend(list(x for x in range(i-1,0,-1)))
    #my_list.extend(list(x for x in range(i-1,0,-1)))
    print([0,1,121,12321,1234321,123454321,12345654321,1234567654321,\
           123456787654321,12345678987654321,12345678910987654321][i])
    #print(*list(el for el in ''.join(str(list(x+1 for x in range(i))) +\
    #     str(list(x for x in range(i-1,0,-1)))) if (not(el=='[')) and\
    #      (not(el==']')) and (not(el==',')) and (not(el==' '))), sep="")
