def func():
    tests = int(input())
    for test in range(tests):
        n,d = map(int, input().split())
        arr = [1]
        if n == 2 and d % 3 == 0:
            arr.append(3)
        elif n >= 3:
            arr.append(3)
        
        if d == 5:
            arr.append(5)

        if n >= 3:
            arr.append(7)
        elif n == 2 and d == 7:
            arr.append(7)

        if n == 2 and d == 9:
            arr.append(9)
        elif n >= 6 or (n >= 3 and d % 3 == 0):
            arr.append(9)
        res = ""
        for a in arr:
            res += str(a) + " "
        print(res)
    return

def find(n):
    if n <= 3:
        return 1
    return 2 * find(n // 4)

if __name__ == '__main__':
    func()
