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
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))
    arr = sorted(arr)
    l = 0
    r = n - 1
    score = 0
    while l < r:
        if arr[l] + arr[r] < k:
            l += 1
        elif arr[l] + arr[r] > k:
            r -= 1
        else:
            score += 1
            l += 1
            r -= 1
    answer.append(str(score))
stdout.write("\n".join(answer) + '\n')

