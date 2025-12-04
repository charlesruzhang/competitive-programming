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
    ans = [0] * n
    for i in range(n):
        s = input()
        x = '1'
        count = 0
        for j in range(n):
            if j == i:
                x= '0'
                continue
            if s[j] == x:
                count +=1
        ans[count] = str(i+1)
    answer.append(" ".join(ans) + '\n')
stdout.write("".join(answer) + '\n')
