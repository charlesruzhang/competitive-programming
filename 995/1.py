def func():
    tests = int(input())
    for i in range(tests):
        n = input()

        arr1 = input().split()
        arr2 = input().split()
        ans = 0
        for i in range(len(arr1)):
            if i == len(arr1) - 1:
                ans += int(arr1[i])
            elif int(arr1[i]) > int(arr2[i+1]):
                ans+= int(arr1[i]) - int(arr2[i+1])
        print(ans)
    return

if __name__ == '__main__':
    func()