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
int F =1;
void solve(int n, vi& a) {
    vi idx(n + 1);
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }
    if (n == 2 && a[0] == 2) {
        //cout << -1 << endl;
        return;
    }
    if (n <= 2) {
        //cout << 0 << endl;
        return;
    }
    int x = n / 4;
    x *= 4;
    vvi ans;
    auto S = [&] (vi& b) {
        if (!b.size()) return;sort(b.begin(), b.end());
        for (int i = 1; i < b.size(); i++) {
            assert(b[i] != b[i-1]);
        }
        vi an;
        vi id;
        int cur = 0;
        for (int x: b) {
            assert(x >= 1);
            assert(x <= n);
            cur ^= x;
            an.push_back(x);
            id.push_back(idx[x]);
        }
        assert(cur == 0);
        sort(an.begin(), an.end());
        sort(id.begin(), id.end());
        for (int i = 0; i < id.size(); i++) {
            a[id[i]] = an[i];
            idx[an[i]] = id[i];
        }
        ans.push_back(id);

    //  cout << " !!!!" << endl;
    // for (int i = 0; i < n; i++) {
    //  cout <<a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //  cout << idx[i+1] << " ";
    // }
    // cout << endl;
    // cout << endl;
    };
    auto print = [&] () {
        assert(ans.size() <= 20);
        // cout << ans.size() << endl;
        // for (int i = 0; i < ans.size(); i++) {
        //     cout << ans[i].size() << " ";
        //     for (int x : ans[i]) {
        //         cout << x + 1 << " ";
        //     }
        //     cout << endl;
        // }
    };
    if ((x & (x - 1)) == 0) {
        if (n == x) {
            if (a[n - 1] != n) {
                //cout << -1 << endl;
                return;
            }
        } else if (n == x + 2) {
                for (int jj = 0; jj < 2; jj++) {
                    vi b;
                    for (int i = 1; i < x; i++) {
                        b.push_back(i);
                    }
                    S(b);
                    vi c;
                    c.push_back(x);
                    c.push_back(x + 1);
                    c.push_back(1);
                    vi c2;
                    c2.push_back(x);
                    c2.push_back(x + 2);
                    c2.push_back(2);
                    vi c3;
                    c3.push_back(x + 1);
                    c3.push_back(x + 2);
                    c3.push_back(3);
                    S(c);
                    S(c2);
                    S(c3);
                    vi d;
                    for (int i = 1; i <= n; i++) {
                        if (i == 1 || i == n) continue;
                        d.push_back(i);
                    } 
                    S(d);
                    vi e;
                    for (int i = 1; i <= n; i++) {
                        if (i == 2 || i == n-1) continue;
                        e.push_back(i);
                    } 
                    S(e);
                    vi f;
                    for (int i = 1; i <= n; i++) {
                        if (i == 3 || i == n-2) continue;
                        f.push_back(i);
                    } 
                    S(f);
                }
                for (int i = 0; i < n; i++) {
                    if (a[i] != i + 1) {
                        F = 0;
                        return;
                    }
                }
                print(); return;
        } else {
            if (n == x + 3) {
                vi b;
                for (int i = 1; i <= n; i++) {
                    b.push_back(i);
                }
                S(b);
                print();
                return;
            } else {
                for (int jj = 0; jj < 6; jj++) {
                    vi b;
                    for (int i = 1; i < x; i++) {
                        b.push_back(i);
                    }
                    S(b);
                    vi c;
                    c.push_back(x);
                    c.push_back(x + 1);
                    c.push_back(1);
                    S(c);
                    vi d;
                    for (int i = 2; i <= n; i++) {
                        d.push_back(i);
                    } 
                    S(d);
                }
                print(); return;
            }
        }
        vi b;
        for (int i = 1; i < x; i++) {
            b.push_back(i);
        }
        S(b);
        print();
        return;
    }
    int cur = 0;
    vi bb;
    vi mark(n + 1);
    for (int i = x; i <= n; i++) {
        cur = cur ^ i;
        bb.push_back(i);
    }
    for (int i = 0; i <= 20; i++) {
        if (cur >> i & 1) {
            bb.push_back(1 << i);
            mark[1 << i] = 1;
        }
    }
    vi b;
    for (int i = 1; i < x; i++) {
        b.push_back(i);
    }
    vi c;
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            c.push_back(i);
        }
    }
    for (int i = 0; i < 6; i++) {
        if (b.size()) S(b); 
        if (bb.size()) S(bb);
        if (c.size()) S(c);
    }
    for (int i = 0; i < n; i++) {
        assert(a[i] == i + 1);
    }
    print();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 50;
    mt19937 rng(31415929);
    while (t--) {
        auto rr = uniform_int_distribution<int>(65538, 65538);
        int n = rr(rng);
        vi a(n);
        iota(a.begin(), a.end(), 1);
        //reverse(a.begin(), a.end());
        shuffle(a.begin(), a.end(), rng);
        solve(n, a);
        if (!F) {
            cout << n << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i]<< " ";
            }
            cout << endl;
        }
    }
    return 0;
}
