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
    vi a(n);
    set<int> s;
    for (int i = 0; i < n;i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    int minn = a[0];
    auto it = s.find(minn);
    int cur = 0;
    while (it != s.end()) {
    	cur++;
    	it = s.lower_bound(*it + 2);
    }
    it = s.lower_bound(minn + 1);
    int maxx = 0;
    while (it != s.end()) {
    	maxx++;
    	it = s.lower_bound(*it + 2);
    }
    cout << max(maxx, cur) << endl;
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
