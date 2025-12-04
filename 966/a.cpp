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
    int a;
    cin >> a;
    vi ans;
    for (int i = 2; i < 100; i ++) {
    	if (i < 10) ans.push_back(100 + i);
    	else ans.push_back(1000+i);
    }
    for (int i = 0; i < ans.size(); i++) {
    	if (ans[i] == a) {
    		cout << "Yes" << endl;
    		return;
    	}
    }
    cout << "NO" << endl;
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
