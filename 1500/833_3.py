from sys import stdin, stdout
import io, os
from collections import defaultdict
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
while test:
    test-=1
    n = int(input())
    arr = list(map(int, input().split()))
    arr.append(0)
    dt = defaultdict(int)
    ans = 0
    summ = 0
    first = 1
    counter = [0]
    for a in arr:
        if first and a != 0:
            summ += a
            if summ == 0:
                ans +=1
        elif a == 0:
            if first:
                first = 0
                summ = 0
                dt[salt] = 1
            else:
                l = []
                for c in counter:
                    l.append(dt[c+salt])
                ans += max(l)
                counter = [0]
                summ = 0
                dt = defaultdict(int)
                dt[salt] = 1
        else: 
            summ += a
            entry = dt[summ+salt]
            if entry == 0:
                counter.append(summ)
            dt[summ+salt] = entry + 1
    answer.append(str(ans))
stdout.write("\n".join(answer) + '\n')
