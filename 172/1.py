def func():
    tests = int(input())
    for test in range(tests):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        arr = sorted(arr,reverse=True)
        count = 0
        for i in range(n):    
            if count + arr[i] > k:
                print(k-count)
                break         
            if count + arr[i] == k:
                print(0)
                break         
            if count + arr[i] < k:
                count += arr[i]
            if i == n-1:
                print(k-count)
    return

if __name__ == '__main__':
    func()
