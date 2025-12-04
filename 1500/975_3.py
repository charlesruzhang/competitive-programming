
from sys import stdin, stdout
import io, os
from collections import defaultdict, deque
import math
import random
import heapq
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
intp = lambda : int(input())
mint = lambda : map(int, input().split())
lint = lambda : list(map(int, input().split()))
while test:
    test-=1
    n = intp()
    ar = defaultdict(list)
    for i in range(n):
        x, y = mint()
        ar[x].append(y)
        ar[y].append(x)
    done = [0] * n
    q = []
    heapq.heappush(q, (0, 1))
    d = 0
    while len(q) > 0:
        x = heapq.heappop(q)
        dd, val = q[0]
        if len(q) > 0 and dd > d:
            
            d += 1 
stdout.write("\n".join(answer) + '\n')

