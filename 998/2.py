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
    n,m = map(int,input().split())
    arr = [0] * n
    ans = 1
    for i in range(n):
        ar = list(map(int, input().split()))
        if not ans:
            continue
        module = ar[0] % n
        for x in ar:
            if x % n != module:
                ans = 0
                break
        arr[module] = str(i + 1)
    if not ans:
        answer.append(str(-1) + '\n')
    else:
        answer.append(" ".join(arr) + '\n')
stdout.write("".join(answer) + '\n')
