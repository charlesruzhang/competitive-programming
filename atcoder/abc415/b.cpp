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
    string s;
    cin >> s;
    int n = s.size();
    vi ans;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '#') {
    		ans.push_back(i+1);
    	}
    }
    for (int i = 0; i < ans.size()/ 2; i++) {
    	cout << ans[2*i] << "," << ans[2*i+1] << endl;
    }
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
