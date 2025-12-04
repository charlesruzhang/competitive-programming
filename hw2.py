
import sys, os, io, random
import numpy as np
input = sys.stdin.readline
n = 3
bags = [[0] * 201 for i in range(3)]
stones = [0] * 100
val = [0] * 100
for i in range(100):
    stones[i] = random.randint(1,20)
    val[i] = random.randint(0,10)
for i in range(100):
    for j in range(2,-1,-1):
        for k in range(200, stones[i]-1, -1):   
            bags[j][k] = max(bags[j][k], bags[j][k-stones[i]]+val[i])
print(stones)
print(val)
print(max(bags[0]),max(bags[1]),max(bags[2]))