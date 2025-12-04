def func():
    tests = int(input())
    for i in range(tests):
        n, m, k= map(int, input().split())
        arr = input().split()
        query = input().split()
        for i in range(len(arr)):
            arr[i] = int(arr[i])
        for i in range(len(query)):
            query[i] = int(query[i])    
        if k < n - 1:
            ans = "0" * m
            print(ans)
            continue
        if k == n:
            ans = "1" * m
            print(ans)
            continue
        ans = ""
        missed = 2
        if query[0] != 1:
            missed = 1
        elif len(query) >= 2:
            for j in range(1,len(query)):
                if query[j] - query[j-1] > 1:
                    missed = query[j-1] + 1
                    break 
                if j == len(query) - 1:
                    missed = n-1    
        for a in arr:
            if a != missed:
                ans+='0'
            else:
                ans+='1'
        print(ans)
    return

if __name__ == '__main__':
    func()