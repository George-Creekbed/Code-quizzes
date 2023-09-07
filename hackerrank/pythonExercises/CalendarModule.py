import calendar

current = list(map(int,input().split()))
today = calendar.weekday(current[2], current[0], current[1])
print(calendar.day_name[today].upper())
