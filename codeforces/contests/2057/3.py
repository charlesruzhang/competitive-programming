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
    l, r = map(int,input().split())
    answer.append("\n".join(ans))
stdout.write("\n".join(answer) + '\n')