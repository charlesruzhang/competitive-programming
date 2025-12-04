from sys import stdin, stdout
import io, os
from collections import defaultdict
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
modulo = 998244353
while test:
    test-=1
    n = int(input())
    arr = list(map(int,input().split()))
    a = [0] * n
    b = [0] * n
    if arr[0] == 0:
        a[0] = b[0] = 1
    else:
        b[0] = 1
    if n == 1:
        answer.append(str(a[0]+b[0]))
        continue
    if arr[1] == 1:
        a[1] = 1
    elif arr[1] == 0:
        a[1] = a[0]
    b[1] = a[0]
    if a[1] == 0 and b[1] == 0:
        answer.append(str(0))
        continue
    done = 0
    for i in range(2, n):
        if arr[i] - arr[i-2] == 1:
            a[i] = (a[i] + b[i-1]) % modulo
        if arr[i] == arr[i-1]:
            a[i] = (a[i] + a[i-1]) % modulo
        b[i] = a[i-1]
        if a[i] == 0 and b[i] == 0:
            answer.append(str(0))
            done = 1
            break
    if not done:
        answer.append(str((a[n-1]+b[n-1]) % modulo))
stdout.write("\n".join(answer) + '\n')

