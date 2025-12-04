def func():
    tests = int(input())
    for test in range(tests):
        n,k = map(int,input().split())
        arr = list(map(int, input().split()))
        count1 = 0
        for c in arr:
            if c == 1:
                count += 1
        count0 = n - count1
        ans = 0
        for j in range((k+1)//2, k+1):
            ans = (ans + choose(count1,j) * choose(count0, k-j)) % (10 ** 9 + 7)
        print(ans)
    return

def choose(n, k):
    if k < 0:
        return 0
    if k == 0 or k == n:
        return 1


if __name__ == '__main__':
    func()