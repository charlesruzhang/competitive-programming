def func():
    tests = int(input())
    for test in range(tests):
        s = input()
        ans = ""
        for c in range(len(s)-1, -1, -1):
            if s[c] == 'p':
                ans += 'q'
            elif s[c] == 'q':
                ans += 'p'
            else: 
                ans += 'w'
        print(ans)
    return
import math
if __name__ == '__main__':
    func()