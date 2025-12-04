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
    int n, k;
    cin >> n >> k;
    int cur = 0;
    map<string, int> ma;
    int cum = 0;
    while (1) {
    	string s;
    	cin >> s;
    	if (s == "Re:") {
    		cum++;
    	} else {
    		ma[s] = max(ma[s], cum);
    		cum = 0;
    		cur++;
    	}
    	if (cur >= k) break;
    }
    ll tot = 0;
    for (auto [s, v]: ma) {
    	tot += v + 1;
    }
    if (tot > n) {
    	cout << "NO" << endl;
    } else {
    	cout << "YES" << endl;
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
