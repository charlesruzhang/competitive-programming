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
    count = 0
    l = 3*n
    r = 5*n
    ans = [str(l),str(r)]
    if n % 2 == 1:
        ans.append(str(4*n))
    cmax = (n - 2) // 2
    for i in range(1, cmax + 1):
        ans.append(str(l+i))
        ans.append(str(r-i))
    answer.append(" ".join(ans))
stdout.write("\n".join(answer) + '\n')

