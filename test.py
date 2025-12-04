from sys import stdin, stdout
import io, os
from collections import defaultdict, deque
import math
import random
import heapq
intp = lambda : int(input())
mint = lambda : map(int,input().split())
lint = lambda : list(map(int, input().split()))
input = stdin.readline
answer = []

def solve():
    a, b = input().split()
    a = list(map(int, a))[::-1]
    b = list(map(int, b))[::-1]
    countb = 0
    c = []
    for x in range(len(a)):
        if countb >= len(b):
            return -1
        if b[countb] < a[x]:
            if countb+1 >= len(b) or b[countb+1] != 1:
                return -1
            else:
                c.append(10 + b[countb] - a[x])
                countb += 2
        else:
            c.append(b[countb] - a[x])
            countb += 1 
    for y in range(countb, len(b)):
        c.append(b[y])
    ans = 0
    timer = 1
    for i in range(len(c)):
        ans += timer * c[i]
        timer *= 10
    return ans


def main():
    salt = random.randint(1,1000)
    test = int(input())
    while test:
        test -= 1
        ans = solve()
        answer.append(str(ans))
    stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()