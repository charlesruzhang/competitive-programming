import sys, os, io
input = sys.stdin.readline
tests = int(input())
answer = []
def solve(brr):
    if len(brr) == 1 and brr[0] == 24:
        return 1
    for i in range(len(brr)):
        for j in range(i+1, len(brr)):
            arr = []
            for k in range(len(brr)):
                if i !=k and j!= k:
                    arr.append(brr[k])
            arr.append(brr[i] + brr[j])
            if solve(arr):
                return 1
            arr[-1] = brr[i] - brr[j]
            
            if solve(arr):
                return 1
            arr[-1] = brr[i] * brr[j]
            if solve(arr):
                return 1
            if brr[j] != 0:
                arr[-1] = float(brr[i]) / float(brr[j])
                if solve(arr):
                    return 1
            if brr[i] != 0:
                arr[-1] = float(brr[j]) / float(brr[i])
                if solve(arr):
                    return 1
    return 0
for _ in range(tests):
    arr = input().split()
    brr = []
    if len(arr) != 4:
        print('No')
        continue
    for a in arr:
        if a == 'A':
            brr.append(1)
        elif a == 'J':
            brr.append(11)
        elif a == 'Q':
            brr.append(12)
        elif a == 'K':
            brr.append(13)
        elif a == 'T':
            brr.append(10)
        else:
            brr.append(int(a))
    if solve(brr): 
        print('Yes')
    else:
        print('NO')

