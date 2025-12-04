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
    cin >> n;
    vi L(n), R(n);
    for (int i = 0; i < n; i++) {
    	cin >> L[i] >> R[i];
    }

    multiset<int> s;
    for (int i = 0; i < n; i++) {
    	auto it = s.upper_bound(R[i]);
    	if (it != s.end()) {
    		s.erase(it);
    	}
    	s.insert(L[i]);
    	cout << s.size() << " ";
    }
    cout << endl;
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
