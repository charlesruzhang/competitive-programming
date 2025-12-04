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
    string x;
    cin >> x;
    int m;
    cin >> m;
    string s, t;
    cin >> s >> t;
    string ans = "";
    for (int i = m - 1; i >= 0; i--) {
    	if (t[i] == 'V') {
    		ans += s[i];
    	}
    }
    ans += x;
    for (int i = 0; i < m; i++) {
    	if (t[i] == 'D') {
    		ans += s[i];
    	}
    }
    cout << ans << endl;
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
