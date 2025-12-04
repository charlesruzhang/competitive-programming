from sys import stdin, stdout
import io, os
from collections import defaultdict
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []

class SegTree():
    def __init__(self, arr):
        self.len = len(arr)
        self.n = 1 << (self.len - 1).bit_length()
        self.min1 = [float('inf')] * 2 * self.n
        self.max1 = [float('-inf')] * 2 * self.n
        self.ans1 = [0] * 2 * self.n
        
        self.min2 = [float('inf')] * 2 * self.n
        self.max2 = [float('-inf')] * 2 * self.n
        self.ans2 = [0] * 2 * self.n
        self.build(arr)
    def build(self,arr):
        for i in range(self.len):
            self.min1[self.n+i] = arr[i] - i
            self.max1[self.n+i] = arr[i] - i
            
            self.min2[self.n+i] = arr[i] + i
            self.max2[self.n+i] = arr[i] + i
        for i in range(self.n -1, 0, -1):
            self.min1[i] = min(self.min1[2*i], self.min1[2*i+1])           
            self.max1[i] = max(self.max1[2*i], self.max1[2*i+1])
            self.ans1[i] = max(self.ans1[2*i], self.ans1[2*i+1], self.max1[2*i+1]-self.min1[2*i])

            self.min2[i] = min(self.min2[2*i], self.min2[2*i+1])             
            self.max2[i] = max(self.max2[2*i], self.max2[2*i+1])
            self.ans2[i] = max(self.ans2[2*i], self.ans2[2*i+1], self.max2[2*i]-self.min2[2*i+1])
    def update(self, idx, val):
        i = idx + self.n
        self.min1[i] = val - idx       
        self.max1[i] = val - idx

        self.min2[i] = val + idx       
        self.max2[i] = val + idx
        while i > 1:
            i //= 2   
            self.min1[i] = min(self.min1[2*i], self.min1[2*i+1])           
            self.max1[i] = max(self.max1[2*i], self.max1[2*i+1])
            self.ans1[i] = max(self.ans1[2*i], self.ans1[2*i+1], self.max1[2*i+1]-self.min1[2*i])

            self.min2[i] = min(self.min2[2*i], self.min2[2*i+1])             
            self.max2[i] = max(self.max2[2*i], self.max2[2*i+1])
            self.ans2[i] = max(self.ans2[2*i], self.ans2[2*i+1], self.max2[2*i]-self.min2[2*i+1])
while test:
    test-=1
    n, q = map(int,input().split())
    arr = list(map(int, input().split()))
    tree = SegTree(arr)
    ans = []
    ans.append(str(max(tree.ans1[1],tree.ans2[1])))
    for _ in range(q):
        p, x = map(int,input().split())
        tree.update(p-1, x)   
        ans.append(str(max(tree.ans1[1],tree.ans2[1])))
    answer.append("\n".join(ans))
stdout.write("\n".join(answer) + '\n')