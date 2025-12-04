def func():
    tests = int(input())
    for i in range(tests):
        n, x, y = map(int, input().split())
        arr = list(map(int, input().split()))
        summ = sum(arr)
        minn, maxx = summ - y, summ - x
        arr = sorted(arr)
        count = 0
        for j in range(len(arr)-1):
            if 2 * arr[j] > maxx:
                break
            count += max(j+1, find(arr,maxx-arr[j]+0.1)) - max(j+1, find(arr,minn-arr[j]-0.1))
        print(count)
    return

def find(arr, target):
    if target < arr[0]:
        return 0
    if target > arr[-1]:
        return len(arr)
    left = 0
    right = len(arr) - 1
    while left < right-1:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid
        if arr[mid] > target:
            right = mid
    return left+1
         

if __name__ == '__main__':
    func()