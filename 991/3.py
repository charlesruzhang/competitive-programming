def func():
    tests = int(input())
    for i in range(tests):
        x = input()
        arr = []
        for c in x:
            arr.append(int(c))
        count2 = 0
        count3 = 0
        for a in arr:
            if a == 2:
                count2+=1
            if a == 3:
                count3+=1
        rem = sum(arr) % 9
        if rem == 0:
            print('YES')
        elif solve(count2, count3, rem):
            print('YES')
        else:
            print('NO')
        
    return

def solve(count2, count3, rem):
    for i in range(min(9,count2+1)):
        for j in range(min(3,count3+1)):
            if (i * 2 + j * 6 + rem) % 9 == 0:
                return True
    return False

if __name__ == '__main__':
    func()
