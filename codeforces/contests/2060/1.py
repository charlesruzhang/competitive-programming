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
    arr = list(map(int, input().split()))
    count = 1
    if arr[0] + arr[1] + arr[2] == arr[3]:
        count+=1
    if arr[2] - arr[1] == arr[0] + arr[1]:
        count+=1
    if arr[2] - arr[1] == arr[3] - arr[2]:
        count+=1

    answer.append(str(min(count,3)))
stdout.write("\n".join(answer) + '\n')
