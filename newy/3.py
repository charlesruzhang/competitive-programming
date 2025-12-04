import sys, os, io
input = sys.stdin.readline
tests = int(input())
answer = []
for _ in range(tests):
    n,k = map(int, input().split())
    
    base = n+1
    accu = 1
    count = 0
    if k == 1:
        print(n * (n+1) // 2)
        continue
    while n >= k:
        if n % 2 == 1:
            count += accu
        accu *= 2
        n //= 2
    if base % 2 == 1:
        count //= 2
    else:
        base //= 2
    print(base * count)