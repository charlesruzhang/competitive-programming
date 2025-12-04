def func():
    tests = int(input())
    for test in range(tests):
        m, a, b, c = map(int, input().split())
        ocu = min(m,a) + min(m,b)
        ocu += min(2 * m - ocu, c)
        print(ocu)
    return
import math
if __name__ == '__main__':
    func()