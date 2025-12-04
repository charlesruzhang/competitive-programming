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
    ans = 0
    return ans


def main():
    test = int(input())
    while test:
        test -= 1
        ans = solve()
        answer.append(str(ans))
    stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()