def func():
    tests = int(input())
    for test in range(tests):
        l,r,G = map(int, input().split())
        left = l// G
        right = r// G
        if left * G != l: 
            left +=1
        done = 0
        for i in range(right - left, -1, -1):
            for j in range(left, right - i + 1):
                # left = j, right = j + i
                if not done and gcd(j, j+i) == 1:
                    print(j*G, (j+i) *G)
                    done = 1
                    break
            if done:
                break
        if not done:
            print(-1, -1)
    return

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

if __name__ == '__main__':
    func()