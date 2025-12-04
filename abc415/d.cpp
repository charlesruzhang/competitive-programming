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
    ll n;
    int m;
    cin >> n >> m;
    vl a(m);
    vector<pll> b(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i] >> b[i].first;
    	b[i].first = a[i] - b[i].first;
    	b[i].second = i;
    }
    sort(b.begin(), b.end());
    ll cur = n;
    ll ans = 0;
    for (int i = 0; i < m; i++) {
    	int x = b[i].second;
    	if (cur < a[x]) {
    		continue;
    	}
    	ll times = (cur - a[x]) / b[i].first + 1;
    	cur -= times * b[i].first;
    	ans += times;
    }
    cout << ans << endl;
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
