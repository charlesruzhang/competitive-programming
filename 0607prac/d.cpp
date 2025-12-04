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
    int q;
    cin >> q;
    multiset<int, greater<>> s;
    multiset<int> t;
    for (int i = 0; i < q; i++) {
    	string z;
    	int x, y;
    	cin >> z >> x >> y;
    	if (z == "+") {
    		s.insert(x);
    		t.insert(y);
    	} else {
    		auto it = s.find(x);
    		s.erase(it);
    		it = t.find(y);
    		t.erase(it);
    	}
    	auto it = s.begin();
    	auto it2 = t.begin();
    	if (it != s.end() && *it2 < *it) {
    		cout << "YES" << endl;
    	} else {
    		cout << "NO" << endl;
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
