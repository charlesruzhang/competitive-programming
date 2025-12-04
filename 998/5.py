
from sys import stdin, stdout
import io, os
from collections import defaultdict, deque
import math
import random
input = stdin.readline
test = int(input())
salt = random.randint(1,1000)
answer = []
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))  
        self.rank = [1] * n          

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x]) 
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1

while test:
    test-=1
    n, m1, m2 = map(int,input().split())
    arr = []
    for i in range(m1):
        x, y = map(int, input().split())
        arr.append([x,y])
    count = 0

    F = UnionFind(n+1)
    G = UnionFind(n+1)
    for i in range(m2):
        x,y = map(int, input().split())
        G.union(x,y)
    for x, y in arr:
        if G.find(x) != G.find(y):
            count+=1
        else:
            F.union(x,y)
    Fc = set()
    for i in range(1,n+1):
        Fc.add(F.find(i))
    Gc = set()
    for i in range(1,n+1):
        Gc.add(G.find(i))
    count += len(Fc) - len(Gc)
    answer.append(str(count))
stdout.write("\n".join(answer) + '\n')

