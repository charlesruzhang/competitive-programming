#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vvi idx(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]].push_back(i);
    }
    int match = 0;
    int cur = 0;
    for (int i = n; i >= 1; i--) {
        cur += idx[i].size();
        if (cur >= 2) {
            cur -= 2;
            match++;
        }
    }
    
    priority_queue<int, vi, greater<>> ans2;
    priority_queue<int> ans1;
    //cout << match << endl;
    priority_queue<int, vi, greater<>> pq;
    priority_queue<int> pq2;
    vi used(n);
    for (int i = n; i >= 1; i--) {
        for (int x : idx[i]) {
            pq.push(x);
            pq2.push(x);
        }
        auto check = [&] () {
            if (!ans1.empty() && !ans2.empty()) {
                int y = ans1.top();
                int z = ans2.top();
                //cout << y << " @ " << z << endl;
                if (y > z) {
                    ans1.pop();
                    ans2.pop();
                    used[y] = used[z] = 0;
                    pq.push(y);
                    pq.push(z);
                    pq2.push(y);
                    pq2.push(z);
                }
            } 
        };
        if (i <= match) {
            int x = pq.top();
            while (used[x]) {
                pq.pop();
                x = pq.top();
            }
            ans1.push(x);
            pq.pop();
            used[x] = 1;

            check();
              
            x = pq2.top();
            while (used[x]) {
                pq2.pop();
                x = pq2.top();
            }
            ans2.push(x);
            pq2.pop();
            used[x] = 1;

            check();
        }
    }
    ll res = 0;
    int zz = ans1.size();
    for (int i = 0; i < zz; i++) {
        int x = ans1.top();
        int y = ans2.top();
        //cout << y << " % " << x << endl;
        ans1.pop();
        ans2.pop();
        res += y - x;
    }
    cout << res << endl;
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
