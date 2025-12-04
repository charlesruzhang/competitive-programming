def func():
    tests = int(input())
    for test in range(tests):
        n = map(int, input().split())
        arr = list(map(int, input().split()))
        depth = [-1] * n
        for i in range(n):
            if depth[i] > 0:
                continue
            depth[i] = 1
            cur = i
            done = [0] * n
            done[i] = 1
            d = 0
            while done[cur] == 0 and depth[arr[cur]-1] == -1:
                depth[cur] = d
                done[cur] = 1
                cur = arr[cur] - 1
                d += 1
            if done[cur] > 0:
                tmp = arr[cur] - 1
                while tmp != cur:
                    depth[tmp] = -2
                    tmp = arr[tmp] -1
            del done[:]
        
    return

if __name__ == '__main__':
    func()