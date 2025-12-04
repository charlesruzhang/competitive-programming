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
    eve = 0
    count = 0
    for a in arr:
        if a % 2 == 1:
            count += 1
        else:
            eve = 1
    if not eve:
        count -= 1
    else:
        count += 1
    answer.append(str(count))
stdout.write("\n".join(answer) + '\n')
