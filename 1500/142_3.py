test = int(input())
while test:
    test-=1
    n = int(input())
    arr = list(map(int, input().split()))
    dt = [0] * (n + 1)
    for i in range(len(arr)):
        dt[arr[i]] = i
    l = (n + 1) // 2
    r = (n + 2) // 2 
    while l > 0 and (l == r or ((dt[l] < dt[l+1]) and (dt[r-1] < dt[r]))):
        l -= 1
        r += 1
    print(l)
    
