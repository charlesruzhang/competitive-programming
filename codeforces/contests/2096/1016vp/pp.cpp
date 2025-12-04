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
    string t;
    cin >> t;
    pair<ll, ll> tot = {0, 0};
    set<pair<ll, ll>> s;
    pair<ll, ll> cur = {0, 0};
    int best = t.size();
    for (int i = 0; i < t.size(); i++) {
    	tot.first = tot.first * 131 + t[i];
    	tot.second = tot.second * 137 + t[i];
    	cur.first = cur.first * 131 + t[i];
    	cur.second = cur.second * 137 + t[i];
    	if (s.find(cur) == s.end()) {
    		cur = {0, 0};
    		best = t.size();
    	} else {
    		best = min(best, i);
    	}
    	s.insert(tot);
    }
    cout << t.substr(0, best) << endl;
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
