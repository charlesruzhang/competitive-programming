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
    arr = list(map(int,input().split()))
    d = defaultdict(int)
    arr = sorted(arr, reverse = 1)
    l = -1
    for i in range(n-1):
        if arr[i] == arr[i+1]:
            l = arr[i]
            arr.pop(i+1)
            arr.pop(i)
            break
    if l == -1:
        answer.append('-1' + ' \n')
        continue
    done = 0
    for i in range(n-3):
        if arr[i] - arr[i+1] < 2 * l:
            ans = [arr[i], arr[i+1], l, l]
            answer.append(" ".join(map(str, ans)) + '\n')
            done = 1
            break
    if not done:
        answer.append('-1' + '\n')
        continue
    
stdout.write("".join(answer) + '\n')
