import sys, os, io
import numpy as np
input = sys.stdin.readline
tests = int(input())
modulo = 998244353
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
            self.tree[i] = (self.tree[2*i] * self.tree[2*i+1]) % modulo
    
    def update(self, idx, val):
        idx += self.n
        self.tree[idx] = val
        while idx > 1:
            idx //= 2
            self.tree[idx] = (self.tree[2*idx] * self.tree[2*idx+1]) % modulo
        
    def get(self, l, r):
        l += self.n
        r += self.n + 1
        res = 1
        while l < r:
            if l % 2 == 1:
                res = (res * self.tree[l]) % modulo
                l += 1
            if r % 2 == 1:
                r -= 1
                res = (res * self.tree[r]) % modulo
            l //= 2
            r //= 2 
        return res
        
for _ in range(tests):
    n,q  = map(int,input().split())
    ar = list(map(int,input().split()))
    br = list(map(int,input().split()))
    crr = []
    arr = sorted(ar)
    argarr = np.argsort(ar)
    brr = sorted(br)
    
    argbrr = np.argsort(br)
    for i in range(n):
        crr.append(min(arr[i],brr[i]))
    seg = SegTree(crr)
    ans = []
    ans.append(seg.get(0, n-1))
    for i in range(q):
        print(arr,brr,argarr,argbrr)
        o, x = map(int,input().split())
        if o == 1:
            ar[x-1] += 1
            idx = argarr[x-1]
            while idx < n and arr[idx] < ar[x-1]:
                idx += 1
            arr[idx-1] = ar[x-1]
            argarr[x-1] = idx-1
            minn = min(arr[idx-1],brr[idx-1])
            seg.update(idx-1, minn)
            ans.append(seg.get(0,n-1))
        if o == 2:
            br[x-1] += 1
            idx = argbrr[x-1]
            while idx < n and brr[idx] < br[x-1]:
                idx += 1
            brr[idx-1] = br[x-1]
            argbrr[x-1] = idx-1
            minn = min(arr[idx-1],brr[idx-1])
            seg.update(idx-1, minn)
            ans.append(seg.get(0,n-1))
    print(ans)