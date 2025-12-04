import sys, os, io
from collections import defaultdict
input = sys.stdin.readline
tests = int(input())
answer = []
class SegTree():
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (2 * self.n)
        self.build(arr)
    
    def build(self, arr):
        for i in range(self.n):
            self.tree[self.n+i] = arr[i]
        for i in range(self.n-1,0,-1):
            self.tree[i] = self.tree[2*i] + self.tree[2*i+1]
    
    def update(self, idx, val):
        idx += self.n
        diff = val- self.tree[idx]
        while idx > 0:
            self.tree[idx] += diff
            idx //= 2
        
    def get(self, l, r):
        l += self.n
        r += self.n + 1
        res = 0
        while l < r:
            if l % 2 == 1:
                res += self.tree[l]
                l += 1
            if r % 2 == 1:
                r -= 1
                res += self.tree[r]
            l //= 2
            r //= 2 
        return res
        
for _ in range(tests):
    n  = int(input())
    dt = defaultdict(int)
    ans = []
    arr = []
    segtree = SegTree([0] * (2 * n + 1 ))
    for i in range(n):
        l, r = map(int, input().split())
        arr.append((l,r))
        if l == r:
            dt[l] += 1
            segtree.update(l, 1)
    for i in range(n):
        l, r = arr[i]
        if l == r:
            if dt[l] == 1:
                ans.append('1')
            else:
                ans.append('0')
        else:
            x = segtree.get(l,r)
            if x == (r - l + 1):
                ans.append('0')
            else:
                ans.append('1')
    answer.append("".join(ans))
sys.stdout.write("\n".join(answer))