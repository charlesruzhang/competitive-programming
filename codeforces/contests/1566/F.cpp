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
    int n, m;
    cin >> n >> m;
    vi a(n);
    set<pii> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
    	s.insert({a[i], i});
    }
    s.insert({INF, n});
    //sort(a.begin(), a.end());
    vector<vector<pii>> T(n+1);
    for (int i = 0; i < m; i++) {
    	int l, r;
    	cin >> l >> r;
    	auto it = s.lower_bound({l, -1});
    	auto it2 = s.lower_bound({r, -1});
    	auto [x, idx] = *it;
    	auto [y, idy] = *it2;
    	if (x == l || y == r) {
    		continue;
    	}
    	if (idx != idy) {
    		continue;
    	}
    	T[idx].push_back({l, r});
    }
    for (int i = 0; i <= n; i++) {
    	sort(T[i].begin(), T[i].end());
    	//for (auto [l, r] : T[i]) {
    		//cout << l << " " << r << endl;
    	//}
    	//cout << " $ " << a[i] << endl;
    }
    vl dp(3);
    int x = T[0].size();
    int minn = a[0];
    for (int j = x - 1; j >= 0; j--) {
    	minn = min(minn, T[0][j].second);
    }
    dp[1] = a[0] - minn;
    dp[2] = 2 * dp[1];
    //cout << endl;
   		//cout << 0 << " " << dp[1] << " " << dp[2] << endl;
   	for (int i = 1; i < n; i++) {
   		vl ndp(3);
   		int x = T[i].size();
   		ll a22 = MAXX, a21 = MAXX, a12 = MAXX, a11 = MAXX;
   		int minn = a[i];
   		for (int j = x - 1; j >= 0; j--) {
   			auto [l, r] = T[i][j];
   			//assert(l >= a[i-1]);
   			a22 = min(a22, 2ll * (l - a[i-1]) + 2ll * (a[i] - minn));
   			a21 = min(a21, 2ll * (l - a[i-1]) + 1ll * (a[i] - minn));
   			a12 = min(a12, 1ll * (l - a[i-1]) + 2ll * (a[i] - minn));
   			a11 = min(a11, 1ll * (l - a[i-1]) + 1ll * (a[i] - minn));
   			minn = min(minn, r);
   		}
   		a22 = min(a22, 2ll * (a[i] - minn));
		a21 = min(a21, 1ll * (a[i] - minn));
		a12 = min(a12, 2ll * (a[i] - minn));
		a11 = min(a11, 1ll * (a[i] - minn));
   		ndp[1] = min(dp[1] + a21, dp[2] + a11);
   		ndp[2] = min(dp[1] + a22, dp[2] + a12);
   		swap(dp, ndp);
   		//cout << i << " " << dp[1] << " " << dp[2] << endl;
   	}
   	x = T[n].size();
   	int maxx = a[n-1];
    for (int j = 0; j < x; j++) {
    	maxx = max(maxx, T[n][j].first);
    }
    ll ans = min(dp[1] + 2 * (maxx - a[n-1]), dp[2] + maxx - a[n-1]);
    cout << ans << endl;
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
