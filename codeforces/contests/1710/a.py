test = int(input())
while test:
    test-=1
    n,m,k = map(int, input().split())
    arr = list(map(int, input().split()))
    count = 0
    alltwo = 1
    for a in arr:
        if a // n >= 2:
            count += a // n
        if a // n > 2:
            alltwo = 0
    if count >= m and (not alltwo or m % 2 == 0):
        print('Yes')
        continue
    count = 0
    alltwo = 1
    for a in arr:
        if a // m >= 2:
            count += a // m
        if a // m > 2:
            alltwo = 0
    if count >= n and (not alltwo or n % 2 == 0):
        print('Yes')
        continue
    print('No')