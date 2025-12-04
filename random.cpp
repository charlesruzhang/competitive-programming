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
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vi v(100);
    for (int i = 0; i < k; i++) {
    	string s;
    	cin >> s;
    	int c = s[0] - 'a';
    	int d = s[1] - '0';
    	if (s.size() >= 3) {
    		d = 10 * d + s[2] - '0';
    	}
    	d--;
    	if (c != d) v[c+d]++;
    }
    int cnt = 0;
    for (int i = 0; i < 100; i++) {
    	if (v[i]) cnt++;
    }
    cout << cnt << endl;
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
