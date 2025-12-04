#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = 2e5;
    long long sum = 0;
    for(int i = 1; i <= n; i ++) {
        int x = i, cnt = 0;
        for(int j = 2; j*j <= x; j ++) {
            if(x%j) continue;
            cnt ++;
            while(x%j==0) x /= j;
        }
        if (x != 1) {
            cnt++;
        }
        sum += (1<<(2 * cnt))*cnt;
    }
    cout << sum;
}