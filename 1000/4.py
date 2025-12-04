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
    n, m = mint()
    arr = lint()
    brr = lint()
    lax = len(arr)
    lbx = len(brr)
    la = lax
    lb = lbx
    if la * lb == 0:
        return [0]
    kmax = min(la, lb, (la+lb)// 3)
    answer.append(str(kmax))
    arr = sorted(arr)
    brr = sorted(brr)
    ans = [0] * (kmax + 1)
    al = deque()
    bl = deque()
    acount = 0
    bcount = 0
    for i in range(1, kmax+1):
        if la * lb < 0:
            print('?????????')
        if la * lb == 0:
            if la == 0:
                r = al.pop()
                cur = ans[i-1] - ans[r] + ans[r-1]
                acount -= 1
                ans[i] = cur + brr[lbx - 1 - bcount] - brr[bcount] + brr[lbx - 2 - bcount] - brr[bcount + 1]
                bcount += 2
                lb -= 3
                bl.append(r)
                bl.append(i)
            else:
                r = bl.pop()
                cur = ans[i-1] - ans[r] + ans[r-1]
                bcount -= 1
                ans[i] = cur + arr[lax - 1 - acount] - arr[acount] + arr[lax - 2 - acount] - arr[acount + 1]
                acount += 2
                la -= 3
                al.append(r)
                al.append(i)
            continue
        x = 0
        if la == 1:
            x = 1
        elif lb == 1:
            x = -1
        if x == -1 or (x!=1 and arr[lax - 1 - acount] - arr[acount] >= brr[lbx - 1 - bcount] - brr[bcount]):
            al.append(i)
            ans[i] = ans[i-1] + arr[lax - 1 - acount] - arr[acount]
            acount += 1
            la -= 2
            lb -= 1
        else:
            bl.append(i)
            ans[i] = ans[i-1] + brr[lbx - 1 - bcount] - brr[bcount]
            bcount += 1
            la -= 1
            lb -= 2
    ans.pop(0)
    return ans


def main():
    test = int(input())
    while test:
        test -= 1
        ans = solve()
        answer.append(" ".join(map(str, ans)))
    stdout.write("\n".join(answer) + '\n')
 
if __name__ == "__main__":
    main()