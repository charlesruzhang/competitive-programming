def func():
    tests = int(input())
    for i in range(tests):
        x = input()
        arr = []
        for c in x:
            arr.append(int(c))
        for i in range(len(arr)-1):
            c = arr[i]
            maxx = 0
            idx = 0
            for j in range(1,9-c):
                if i+j >= len(arr):
                    break
                if maxx < arr[i+j] - c - j:
                    maxx = arr[i+j] - c - j
                    idx = j
            if maxx > 0:
                tmp = arr[i+idx] - idx
                for k in range(idx,0,-1):
                    arr[i+k] = arr[i+k-1]
                arr[i] = tmp
        ans = ""
        for a in arr:
            ans += str(a)
        print(ans)
    return  

if __name__ == '__main__':
    func()
