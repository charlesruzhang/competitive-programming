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
    int q;
    cin >> q;
    ll tot = 0;
    multiset<int> s;
    int cur = 0;
    auto it = s.begin();
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	if (x == 1) {
    		int a, b;
    		cin >> a >> b;
    		tot += b;
    		cur ++;
    		s.insert(a);
    		if (s.size() == 1) {
    			it = s.begin();
    		} else if (a > *it) {
    			++it;
    		}
    	} else {

    	}
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
