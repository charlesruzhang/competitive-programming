
from sys import stdin, stdout
import io, os
from collections import defaultdict, deque
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
modulo = 998244353
while test:
    test-=1
    n, m1, m2 = map(int,input().split())
   
    answer.append(str(count))
stdout.write("\n".join(answer) + '\n')

