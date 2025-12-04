from collections import defaultdict
def func():
    tests = int(input())
    for test in range(tests):
        n = int(input())
        arr = list(map(int, input().split()))
        dt = defaultdict(int)
        for x in arr:
            dt[x] += 1
        count = 0
        tmp = 1
        for k in dt.keys():
            if dt[k] >= 2:
                count += 1
            else:
                count += 2 * tmp
                tmp = 1 - tmp
        print(int(count))
        
    return

if __name__ == '__main__':
    func()
