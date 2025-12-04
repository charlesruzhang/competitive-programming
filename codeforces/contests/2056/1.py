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
    n,m = map(int, input().split())
    xx,yy= map(int, input().split())
    xt,yt= m,m           
    for i in range(1,n):
        x,y = map(int, input().split())
        xt,yt = x+xt,y+yt
    ans = 2 * (xt + yt)
    answer.append(str(ans))
stdout.write("\n".join(answer) + '\n')
