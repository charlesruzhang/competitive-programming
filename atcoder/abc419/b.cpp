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
    multiset<int> s;
    while (q--) {
    	int a;
    	cin >> a;
    	if (a == 1) {
    		int x;
    		cin >> x;
    		s.insert(x);
    	} else {
    		auto it = s.begin();
    		cout << *it << endl;
    		s.erase(it);
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
