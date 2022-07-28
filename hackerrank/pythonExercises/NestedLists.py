if __name__ == '__main__':
    names = []
    scores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        names.append(name)
        scores.append(score)

n = len(names)
grades = [[names[i], scores[i]] for i in range(n)]
grades.sort(key = lambda pair: pair[1])
how_many_min = scores.count(grades[0][1])
for i in range(how_many_min):
    grades.pop(0)
how_many_prints = scores.count(grades[0][1])
prints = [grades[i] for i in range(how_many_prints) \
          if grades[i][1] == grades[0][1]]
prints.sort(key = lambda pair: pair[0])
for el in prints:
    print(el[0])
