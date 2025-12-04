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
void solve() {
    int n;
    string c;
    cin >> n >> c;
    string s;
    cin >> s;
    vector<char> ch(2 * n);
    for (int i = 0; i < 2 * n; i++) {
    	ch[i] = s[i % n];
    }
    vi last(2 * n + 1);
    for (int i = 2 * n - 1; i >= 0; i--) {
    	last[i] = (ch[i] == 'g') ? i : last[i+1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	if (ch[i] == c[0]) {
    		ans = max(ans, last[i] - i);
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
