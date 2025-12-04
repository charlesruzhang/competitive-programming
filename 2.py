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
salt = random.randint(1,1000)
answer = []

def solve():
    n,m = mint()
    if (n == 0 and m == 0):
        return -1
    summ = 0
    for i in range(n):
        summ+= intp()
    for i in range(m):
        summ -= intp()
    print(summ)
    return 0


def main():
    test = 1
    while True:
        test -= 1
        x = solve()
        if (x < 0):
            break
        #answer.append(str(ans))
    #stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()