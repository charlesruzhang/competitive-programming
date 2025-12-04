import sys, os, io
input = sys.stdin.readline
tests = int(input())
answer = []
for _ in range(tests):
    n  = int(input())
    arr = list(map(int,input().split()))
    done = 0
    for i in range(len(arr)-1):
        if (arr[i] <= arr[i+1] and 2*arr[i] > arr[i+1]) or (arr[i] >= arr[i+1] and 2*arr[i+1] > arr[i]):
            print('Yes')
            done = 1
            break
    if not done:
        print('No')