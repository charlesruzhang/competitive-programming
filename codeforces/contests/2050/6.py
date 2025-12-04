def func():
    tests = int(input())
    for i in range(tests):
        n, m = map(int,input().split())
        arr = input().split()
        for j in range(len(arr)):
            arr[j] = int(arr[j])
        ans = ""
        diffarr = [0] * (len(arr)-1)
        for j in range(len(arr)-1):
            diffarr[j] = abs(arr[j] - arr[j+1])
        segtree = SegTree(diffarr)

        for j in range(m):
            l, r = map(int,input().split())
            X = segtree.query(l-1,r-2)
            ans += str(X)
            if j != m-1:
                ans+= " "
        print(ans)

    return  
class SegTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (2 * self.n)
        self.build(arr)

    def build(self,arr):
        for i in range(self.n):
            self.tree[self.n+i] = arr[i]
        for i in range(self.n-1, 0, -1):
            self.tree[i] = gcd(self.tree[2*i], self.tree[2*i+1])

    def query(self, l, r):
        left = l + self.n
        right = r + self.n + 1
        result = 0
        while left < right:
            if left % 2 == 1:
                result = gcd(result, self.tree[left])
                left += 1
            if right % 2 == 1:
                right -=1
                result = gcd(result, self.tree[right])
            left = left // 2
            right = right // 2
        return result

def gcd (x,y):
    while(y):
        x, y = y, x % y
    return x

if __name__ == '__main__':
    func()
