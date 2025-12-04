from sys import stdin, stdout
import io, os
from collections import defaultdict, deque
import math
import random
import heapq
intp = lambda : int(input())
mint = lambda : map(int,input().split())
lint = lambda : list(map(int, input().split()))
input = stdin.readline
salt = random.randint(1,1000)
answer = []

def solve():
    n, l, r = mint()
    arr = lint()
    le = []
    re = []
    l-=1
    r-=1
    for i in range(l):
        le.append(arr[i])
    for i in range(l,r+1):
        le.append(arr[i])
        re.append(arr[i])
    for i in range(r+1, n):
        re.append(arr[i])
    le = sorted(le)
    re = sorted(re)
    summ1 = 0
    summ2 = 0
    for i in range(r-l+1):
        summ1+=le[i]
        summ2+=re[i]
    return min(summ1, summ2)


def main():
    test = int(input())
    while test:
        test -= 1
        ans = solve()
        answer.append(str(ans))
    stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()