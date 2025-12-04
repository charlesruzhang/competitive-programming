
import sys, os, io
input = sys.stdin.readline
tests = int(input())
answer = []
for _ in range(tests):
    n,q = map(int,input().split())
    arr = list(map(int, input().split()))
    Q = 0
    ans = ["0"] * n
    for i in range(n-1, -1, -1):
        if arr[i] <= Q:
            ans[i] = "1"
        elif arr[i] > Q and Q < q:
            Q+=1
            ans[i] = "1"
    answer.append("".join(ans))
sys.stdout.write("\n".join(answer))