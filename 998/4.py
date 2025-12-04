
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
    ans = 'Yes'
    for i in range(n-1):
        if arr[i] > arr[i+1]:
            ans = 'No'
            break
        arr[i+1] -= arr[i]
    answer.append(ans)
stdout.write("\n".join(answer) + '\n')

