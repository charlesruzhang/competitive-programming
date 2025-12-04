def func():
    tests = int(input())
    for _ in range(tests):
        n = int(input())
        arr = list(map(int,input().split()))
        pivot = n
        minn = 0
        maxx = 0
        mind = 0
        maxc = 0
        cur = 0
        for i in range(n):
            if arr[i] != 1 and arr[i] != -1:
                pivot = i
                break
            
        for i in range(pivot-1,-1,-1):
            cur += arr[i]
            minn = min(minn, cur)
            maxx = max(maxx, cur)
            maxc = max(maxc, cur-minn)
            mind = min(mind, cur-maxx)

        if pivot == n:
            print(maxc - mind + 1)
            res = ""
            for x in range(mind, maxc+1):
                res += str(x) + " "
            print(res)
            continue

        cur = 0
        minnt = 0
        maxxt = 0
        for i in range(pivot+1, n):
            cur += arr[i]
            minnt = min(minnt, cur)
            maxxt = max(maxxt, cur)  
            maxc = max(maxc, cur-minnt)
            mind = min(mind, cur-maxxt)
        
        cur = 0
        minn = minn + minnt
        maxx = maxx + maxxt
        if maxc < arr[pivot] + minn:
            res = ""
            count = 0
            for x in range(mind, maxc+1):
                res += str(x) + " "
                count+=1
            for x in range(arr[pivot]+minn, arr[pivot]+maxx+1):
                res += str(x) + " "
                count+=1
        elif arr[pivot]+maxx < mind:
            res = ""
            count = 0
            for x in range(arr[pivot]+minn, arr[pivot]+maxx+1):
                res += str(x) + " "
                count+=1
            for x in range(mind, maxc+1):
                res += str(x) + " "
                count+=1
        else:
            res = ""
            count = 0
            l = min(arr[pivot]+minn, mind)   
            r = max(arr[pivot]+maxx, maxc)
            for x in range(l, r+1):
                res += str(x) + " "
                count+=1
        print(count)
        print(res)
    return


if __name__ == '__main__':
    func()
