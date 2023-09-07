from collections import Counter as counter
def minion_game(string):
    # your code goes here
    substrings = []
    consonants = 'bcdfghjklmnpqrstvwxyz'.upper()
    vowels = 'aeiou'.upper()
    # obtain all possible substrings
    for i in range(len(string)):
        for j in range(i+1, len(string)+1):
            substrings.append(string[i: j])

    # use Counter to create a dictionary of substrings frequencies
    how_many = counter(substrings)
    
    # assign substrings to Stuart (1st is a consonant) 
    # or Kevin (1st is a vowel)
    stuart = {}
    kevin = {}
    for u, v in how_many.items():
        if u[0] in consonants:
            stuart[u] = v
        elif u[0] in vowels:
            kevin[u] = v

    # determine output
    if sum(stuart.values()) > sum(kevin.values()):
        print("Stuart", sum(stuart.values()))
    elif sum(stuart.values()) < sum(kevin.values()):
        print("Kevin", sum(kevin.values()))
    else:
        print("Draw") 
        
# OR BETTER, LINEAR COMPLEXITY WITHOUT
# USING THE COUNTER MODULE:
#def minion_game(string):
    #s = string
    #vowels = 'AEIOU'

    #kevsc = 0
    #stusc = 0
    #for i in range(len(s)):
        #if s[i] in vowels:
            #kevsc += (len(s)-i)
        #else:
            #stusc += (len(s)-i)

    #if kevsc > stusc:
        #print("Kevin", kevsc)
    #elif kevsc < stusc:
        #print("Stuart", stusc)
    #else:
        #print("Draw")   

if __name__ == '__main__':
    s = input()
    minion_game(s)
