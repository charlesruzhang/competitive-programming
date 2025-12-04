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
    int n;
    ll w;
    cin >> n >> w;
    vi p(n, -1);
    for (int i = 1; i < n; i++) {
    	cin >> p[i];
    	p[i]--;
    }
    vi steps(n);
    map<pii, int> ma;
    for (int i = 1; i < n; i++) {
    	int cur = 1;
    	int y = i - 1;
    	while (y != p[i]) {
    		ma[{y, p[y]}] = i;
    		y = p[y];
    		cur++;
    	}
    	ma[{p[i], i}] = i;
    	steps[i] = cur;
    }
    int y = n - 1;
    int cur = 0;
    while (y != 0) {
    	ma[{y, p[y]}] = 0;
    	y = p[y];
    	cur++;
    }
    steps[0] = cur;
    ll rem = w;
    ll live = n;
    for (int i = 1; i < n; i++) {
    	int u;
    	ll x;
    	cin >> u >> x;
    	u--;
    	rem -= x;
    	int v = p[u];
    	int first = ma[{u, v}];
    	steps[first]--;
    	if (steps[first] == 0) {
    		live--;
    	}
    	int second = ma[{v, u}];
    	steps[second]--;
    	if (steps[second] == 0) {
    		live--;
    	}
    	cout << live * rem + (w - rem) * 2 << " ";
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
