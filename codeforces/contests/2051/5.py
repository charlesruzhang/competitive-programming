def func():
    tests = int(input())
    for test in range(tests):
        n, k = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        a = sorted(a)
        b = sorted(b)
        ida = 0
        idb = 0
        maxx = 0
        prev = -1
        while ida < n and idb < n:
            if a[ida] <= b[idb]:
                if a[ida] == prev:
                    ida += 1
                    continue
                prev = a[ida]
                if ida - idb <= k:
                    maxx = max(maxx, (n - idb) * a[ida] )
                ida += 1
            else:
                if b[idb] == prev:
                    idb += 1
                    continue
                prev = b[idb]
                if ida - idb <= k:
                    maxx = max(maxx, (n - idb) * b[idb]) 
                idb += 1
        for i in range(idb, n):
            if b[i] == prev:
                continue
            prev = b[i]
            if n - i <= k:
                maxx = max(maxx, (n - i) * b[i]) 
        print(maxx) 
    return

if __name__ == '__main__':
    func()