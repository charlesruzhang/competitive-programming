
def func():
    tests = int(input())
    for test in range(tests):
        n = int(input())
        arrl = []
        arrr = []
        for i in range(n):
            l, r = map(int, input().split())
            arrl.append([l,r,i])
            arrr.append([l,r,i])
        arrl.sort(key = lambda x: (x[0], -x[1]))
        arrr.sort(key = lambda x: (x[1], -x[0]))
        skipped = [0] * n
        for i in range(n-1):
            if arrl[i][0] == arrl[i+1][0] and arrl[i][1] == arrl[i+1][1]:
                skipped[arrl[i][2]] = 1
                skipped[arrl[i+1][2]] = 1
        
    return

if __name__ == '__main__':
    func()