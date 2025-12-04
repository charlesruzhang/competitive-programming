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
void solve() {
    int n;
    cin >> n;
    vl p1(1e6+1);
    vl p2(1e6+1);
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= 1e6; i++) {
        p1[i] = p1[i-1] * 131;
        p2[i] = p2[i-1] * 137;
    }
    vector<set<ll>> s1(1e6+1), s2(1e6+1);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m = s.size();
        ll cur1 = 0;
        ll cur2 = 0;
        for (int j = 0; j < m; j++) {
            cur1 = cur1 * 131 + (s[j] - 'A');
            cur2 = cur2 * 137 + (s[j] - 'A');
        }
        if (s1[m].find(cur1) != s1[m].end() && s2[m].find(cur2) != s2[m].end()) {
            flag = 1;
        }
        s1[m].insert(cur1);
        s2[m].insert(cur2);
        for (int j = 1; j < m; j++) {
            cur1 -= (s[j-1] - 'A') * p1[m-1];
            cur1 *= 131;
            cur1 += (s[j-1] - 'A');
            s1[m].insert(cur1);
        }
        for (int j = 1; j < m; j++) {
            cur2 -= (s[j-1] - 'A') * p2[m-1];
            cur2 *= 137;
            cur2 += (s[j-1] - 'A');
            s2[m].insert(cur2);
        }
        cur1 = 0;
        cur2 = 0;
        for (int j = m - 1; j >= 0; j--) {
            cur1 = cur1 * 131 + (s[j] - 'A');
            cur2 = cur2 * 137 + (s[j] - 'A');
        }
        s1[m].insert(cur1);
        s2[m].insert(cur2);
        for (int j = m - 2; j >= 0; j--) {
            cur1 -= (s[j+1] - 'A') * p1[m-1];
            cur1 *= 131;
            cur1 += (s[j+1] - 'A');
            s1[m].insert(cur1);
        }
        for (int j = m - 2; j >= 0; j--) {
            cur2 -= (s[j+1] - 'A') * p2[m-1];
            cur2 *= 137;
            cur2 += (s[j+1] - 'A');
            s2[m].insert(cur2);
        }
    }
    cout << ((flag) ? "Yes" : "No") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
