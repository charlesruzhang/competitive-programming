def func():
    tests = int(input())
    for i in range(tests):
        n, m = map(int, input().split())
        count = 0
        for j in range(n):
            w = input()
            if len(w) <m:
                m -= len(w)
                count+=1
            elif len(w) == m:
                print(count+1)
                m = -1
            elif len(w) > m and m != -1:
                print(count)
                m = -1
        if m!= -1:
            print(count)
    return

if __name__ == '__main__':
    func()
