def func():
    tests = int(input())
    for i in range(tests):
        a = input()
        b = input()
        c = input()
        arr = [[0]*(len(b)+1) for i in range(len(a)+1)]
        for i in range(len(a)+1):
            for j in range(len(b)+1):
                if i == 0 and j != 0:
                    count = 0
                    if c[j-1] != b[j-1]:
                        count+=1
                    arr[i][j] = arr[i][j-1] + count
                if i != 0 and j == 0:
                    count = 0
                    if c[i-1] != a[i-1]:
                        count+=1
                    arr[i][j] = arr[i-1][j] + count
                if i != 0 and j !=0:
                    count1 = 0
                    count2 = 0
                    if c[i+j-1] != a[i-1]:
                        count1+=1
                    if c[i+j-1] != b[j-1]:
                        count2+=1   
                    arr[i][j] = min(arr[i][j-1] + count2, arr[i-1][j] + count1)
        print(arr[-1][-1])
    return  

if __name__ == '__main__':
    func()
