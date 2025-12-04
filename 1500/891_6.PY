from sys import stdin, stdout
import io, os
from collections import defaultdict
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
while test:
    test-=1
    n = int(input())
    arr = list(map(int, input().split()))
    dt = defaultdict(int)
    ans = []
    for a in arr:
        dt[a+salt] += 1
    q = int(input())
    for i in range(q):
        x, y = map(int, input().split())
        if x ** 2 - (4 * y) < 0:
            ans.append('0')
            continue
        t = math.sqrt(x ** 2 - (4 * y))
        a, b = (x + int(t)) // 2, (x - int(t)) // 2
        if a + b != x or a * b != y:
            ans.append('0')
            continue
        if a != b:
            ans.append(str(dt[a+salt] * dt[b+salt]))
        else:
            ans.append(str((dt[a+salt] * (dt[a+salt] - 1)) // 2))
    stdout.write(" ".join(ans) + '\n')
