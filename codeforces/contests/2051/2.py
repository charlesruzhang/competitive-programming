def func():
    tests = int(input())
    for i in range(tests):
        n, a, b, c = map(int, input().split())
        rem = n % (a+b+c)
        divv = n // (a+b+c)
        remm = 0
        if rem == 0:
            remm = 0
        elif rem <= a:
            remm = 1
        elif rem <= a+b:
            remm = 2
        else:
            remm = 3
        print(3 * divv + remm)
    return

if __name__ == '__main__':
    func()