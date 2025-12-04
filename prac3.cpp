#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const ll MOD = 998244353;
const ll MAXX = 1e9;
const ld EPS = 1e-9;
vi vv;
void solve() {
    int n;
    cin >> n;
    vi a;
    vi minn(n, MAXX);
    vi mex(n, 0);
    int cc = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cc++;
            if (cc < 2) {
                a.push_back(0);
            }
        } else {
            a.push_back(x);
        }
    }
    n = a.size();
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            minn[i] = min(minn[i-1], a[i]);
        } else {
            minn[0] = a[0];
        }
    }
    queue<int> q1;
    priority_queue<int, vi, greater<>> q2;
    vi seen(n, 0);
    for (int i = 0; i < n; i++) {
        q1.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= n -1 && !seen[a[i]]) {
            seen[a[i]] = 1;
            if (q1.front() == a[i]) {
                q1.pop();
                while (!q1.empty() && !q2.empty() && (q1.front() == q2.top())) {
                    q1.pop();
                    q2.pop();
                }
            } else {
                q2.push(a[i]);
            }
        }
        mex[i] = q1.front();
    }
    for (int i = 0; i < n-1; i ++) {
        if (minn[i] < mex[i+1]) {
            cout << n - 1<< endl;
            return;
        }
    }
    cout << n << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}