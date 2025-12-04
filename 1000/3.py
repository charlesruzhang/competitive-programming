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
    n = intp()
    arr = [0] * (n + 1)
    el = defaultdict(list)
    for i in range(n-1):
        a, b= mint()
        arr[a] += 1
        arr[b] += 1 
        el[a].append(b)
        el[b].append(a)
    
    if n == 2:
        return 0
    idx = [0]
    maxx = arr[0]
    for i in range(1, n+1):
        if maxx < arr[i]:
            idx = [i]
            maxx = arr[i]
        elif maxx == arr[i]:
            idx.append(i)
    if len(idx) >= 3:
        return 2 * maxx - 1
    elif len(idx) == 1:
        for x in el[idx[0]]:
            arr[x] -= 1
        arr[idx[0]] = 0
        return maxx + max(arr) - 1
    else:
        if idx[1] in el[idx[0]]:
            return 2 * maxx - 2
        else:
            return 2 * maxx - 1


def main():
    test = int(input())
    while test:
        test -= 1
        ans = solve()
        answer.append(str(ans))
    stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()