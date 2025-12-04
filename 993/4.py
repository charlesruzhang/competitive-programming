
def func():
    tests = int(input())
    for test in range(tests):
        n = int(input())
        arr = list(map(int, input().split()))
        brr = [0] * (n + 1)
        ans = [0] * n 
        brr[arr[0]] = 1
        ans[0] = arr[0]
        for i in range(1,n):
            if brr[arr[i]] != 1:
                ans[i] = arr[i]
                brr[arr[i]] = 1
        cur = 1
        for i in range(n):
            if ans[i] == 0:
                while brr[cur] != 0:
                    cur += 1
                ans[i] = cur
                cur += 1
        result = ""
        for x in ans:
            result += str(x) + " "
        print(result)
    return
if __name__ == '__main__':
    func()