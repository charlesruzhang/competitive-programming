def func():
    tests = int(input())
    for i in range(tests):
        n = int(input())
        x = input().split()
        for j in range(n):
            x[j] = int(x[j])
        summ = sum(x)
        if summ != (summ // n) * n:
            print('NO')
            continue
        target = summ // n
        count = 0
        for j in range(0, n, 2):
            count += x[j]
        if count == target * ((n + 1) // 2):
            print('YES')
        else:
            print('NO')

    return

if __name__ == '__main__':
    func()
