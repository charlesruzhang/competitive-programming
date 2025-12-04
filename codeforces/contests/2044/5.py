def func():
    tests = int(input())
    for test in range(tests):
        k,l1,r1,l2,r2 = map(int, input().split())
        ans = 0
        l3, r3 = l2, r2
        while True:
            l, r = max(l1, l3), min(r1 , r3)
            if r < l:
                if l1 > r3:
                    break
            else:
                ans += r - l + 1
            l3, r3 = ((l3 - 1) // k) + 1, (r3 // k)
        print(ans)
    return

if __name__ == '__main__':
    func()