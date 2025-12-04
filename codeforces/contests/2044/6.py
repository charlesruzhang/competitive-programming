from collections import defaultdict
def func():
    tests = 1
    for test in range(tests):
        n, m, q = map(int, input().split())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        sa = sum(a)
        sb = sum(b)
        A,B=[0]*(2*n+1),[0]*(2*m+1)
        for x in a:
            A[x] = 1
        for x in b:
            B[x] = 1
        for _ in range(q):
            x = int(input())
            bol = False
            for i in range(1,int(abs(n)**0.5)+1):
                if x%i:
                    continue
                d = x//i
                for p,q in ((i,d), (d,i), (-i,-d), (-d,-i)):
                    bol |= abs(sa-p)<=n and abs(sb-q)<=m and A[sa-p] and B[sb-q]
            if bol:
                print('YES')
            else:
                print("NO")
    return

if __name__ == '__main__':
    func()