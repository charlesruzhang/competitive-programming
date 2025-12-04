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
    if n == 6:
        ans = ['1','1','2','3','1','2']
    else:
        ans = ['1'] * n
        for i in range(1,n-2):
            ans[i] = str(i + 1)
    answer.append(" ".join(ans))
stdout.write("\n".join(answer) + '\n')

