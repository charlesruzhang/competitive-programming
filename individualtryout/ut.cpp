// By Auchenai01
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
const int INF = 1e9 + 7;
void solve(ll n) {
    cout << "n = " << n << endl;
    // if (n == 45) {
    //     cout << "5055555555" << endl;
    //     return;
    // }
    // if (n == 72) {
    //     cout << "8088888888" << endl;
    //     return;
    // }
    // if (n == 81) {
    //     ll cur = 90;
    //     while (cur % 81 != 0) {
    //         cur = cur * 10 + 9;
    //     }
    //     cout << cur << endl;
    //     return;
    // }
    if (n >= 10000) {
        set<ll> arr;
        ll x = n;
        while (x) {
            arr.insert(x % 10);
            x /= 10;
        }
        if (arr.size() == 1) {
            cout << n << endl;
            return;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    if (n == 54) {
        ll minn = 1e18;
        for (int i = 0; i < 1024; i++) {
            ll cur = 0;
            for (int j = 0; j < 10; j++) {
                if ((1 << j) & i) {
                    cur = cur * 10 + 2;
                } else {
                    cur = cur * 10 + 8;
                }
                vi b;
                ll y = cur;
                while (y) {
                    b.push_back(y % 10);
                    y /= 10;
                }
                sort(b.begin(), b.end());
                ll G = 0;
                do {
                    ll tot = 0;
                    for (int z : b) {
                        tot = tot * 10 + z;
                    }
                    G = gcd(G, tot);
                    if (G < n) break;
                } while (next_permutation(b.begin(), b.end()));
                if (G == n) {
                    minn = min(minn, cur);
                }
            }
        }
        cout << minn << endl;
        return;
    }
    for (int i = 1; i <= 1e4; i++) {

        ll x = n * i;
        vi b;
        ll y = x;
        while (y) {
            b.push_back(y % 10);
            y /= 10;
        }
        sort(b.begin(), b.end());
        ll G = 0;
        do {
            ll tot = 0;
            for (int z : b) {
                tot = tot * 10 + z;
            }
            G = gcd(G, tot);
            if (G < n) break;
        } while (next_permutation(b.begin(), b.end()));
        if (G == n) {
            cout << n << " " << x << endl;
            return;
        }
    }
    
    //cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    
    for (int i = 1; i <= 100; i++) {
        solve(i);
    }
    return 0;
}
