
cha = ['n','a','r','e','k']
def func():
    tests = int(input())
    for test in range(tests):
        n,m = map(int,input().split())
        arr = [""]*n
        for i in range(n):
            arr[i] = input()
        endc = [float('-inf')] * 5
        for i in range(n):
            tmparr = []
            dp = [float('-inf')] * 5
            for j in range(5):
                if endc[j] == float('-inf') and j != 0:
                    continue
                dp[j]= endc[j]
                cur = j
                for k in range(m):
                    c = arr[i][k]
                    if cha[cur] == c:
                        cur = (cur + 1) % 5
                        dp[j] += 1
                    elif c in cha:
                        dp[j] -= 1
                tmparr.append([cur, j])
            for p, y in tmparr:
                endc[p] = max(endc[p], dp[y]) 
        ans = 0
        for i in range(5):
            ans = max(ans, endc[i] - 2 * i)
        print(ans)
            

    return

if __name__ == '__main__':
    func()