def func():
    tests = int(input())
    for test in range(tests):
        n = int(input())
        count = 0
        print(find(n))
    return

def find(n):
    if n <= 3:
        return 1
    return 2 * find(n // 4)

import math
if __name__ == '__main__':
    n = 2**58 -2
    result = int(math.log(n) / math.log(4))
    ans = 1
    x = n
    while (x>3):
        x = x // 4
        ans = ans * 2
    k = 1
    x = 1
    while (x*4) <= n:
        k *= 2
        x *= 4
    print(n-10**18,n, find(n), 2 ** result, k)
