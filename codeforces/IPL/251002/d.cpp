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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vi p(n);
    x--; y--;
    for (int i = 0; i < n; i++) {
    	cin >> p[i];
    	p[i]--;
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    auto f = [&] (int x) {
    	int cur = x;
    	int first = 1;
    	int cnt = 0;
    	ll ans = 0;
    	ll tot = 0;
    	while (cur != x || first) {
    		first = 0;
    		ans = max(ans, 1ll * (k - cnt) * a[cur] + tot);
    		tot += a[cur];
    		cur = p[cur];
    		cnt++;
    		if (cnt == k + 1) {
    			return ans;
    		}
    	}
    	return ans;
    };
    ll fx = f(x);
    ll fy = f(y);
    cout << (fx > fy ? "Bodya" : (fx == fy ? "Draw" : "Sasha")) << endl;
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
