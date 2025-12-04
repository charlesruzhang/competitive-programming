
from sys import stdin, stdout
import io, os
from collections import defaultdict
import math
import random
import heapq
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
while test:
    test-=1
    n,m = map(int,input().split())
    arr = list(map(int, input().split()))
    brr = list(map(int, input().split()))
    pq = []
    aa = []
    for a in arr:
        heapq.heappush(aa, -a)
    for b in brr:
        heapq.heappush(pq, -b)
    while len(pq) > 0:
        if len(pq) > len(aa):
            break
        x = -pq[0]
        if x < -aa[0]:
            break
        elif x == -aa[0]:
            heapq.heappop(aa)
            heapq.heappop(pq)
        else:
            heapq.heappop(pq)
            heapq.heappush(pq, -(x // 2))
            heapq.heappush(pq, -((x + 1)// 2))
    if len(aa) == 0:
        ans = 'Yes'
    else:
        ans = 'No'
    answer.append(ans)
stdout.write("\n".join(answer) + '\n')

