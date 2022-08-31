import datetime

def time_delta(t1, t2):
    date_1 = datetime.datetime.strptime(t1, "%a %d %b %Y %H:%M:%S %z")
    date_2 = datetime.datetime.strptime(t2, "%a %d %b %Y %H:%M:%S %z")
    # fuse = date_1.tzinfo.utcoffset(date_1)#time.timezone(date_1.tzname())
    diff = date_1 - date_2
    
    return abs(round((diff.total_seconds())))

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        t1 = input()
        t2 = input()
        delta = time_delta(t1, t2)
        print(delta)
