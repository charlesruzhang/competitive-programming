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
    vector<vector<pii>> q(n, vector<pii>(2));
    vvl dp(n+1, vl(3));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
    	string x, y;
    	int a, b;
    	cin >> x >> a >> y >> b;
    	if (x == "+") {
    		q[i][0] = pii(0, a);
    	} else {
    		q[i][0] = pii(1, a);
    	}
    	if (y == "+") {
    		q[i][1] = pii(0, b);
    	} else {
    		q[i][1] = pii(1, b);
    	}
    }

    for (int i = 1; i <= n; i++) {
    	ll l = 0;
    	ll r = 0;
    	ll z = 0;
    	ll summ = 0;
    	for (int j = 0; j < i; j++) {
            ll f[2];
            function <void(int)> func = [&](int x) {
                f[x] = dp[j][x] + dp[j][2];
                f[1-x] = dp[j][1-x];
                ll val = 0;
                for (int k = j; k < i; k++) {
                    ll tf, ts;
                    if (k == i - 1) {
                        tf = f[x];
                        ts = f[1-x];
                    }
                    if (q[k][x].first) {
                        f[x] = f[x] * q[k][x].second;
                    } else {
                        f[x] += q[k][x].second;
                    }
                    if (q[k][1-x].first) f[x] += f[1-x] * (q[k][1-x].second - 1);
                    else f[x] += q[k][1-x].second;

                    if (k == i - 1) {
                        val = f[x] + f[1-x] - tf - ts;
                        f[x] = tf;
                        f[1-x] = ts;
                    }
                }
                if (summ < f[x] + f[1-x] + val) {
                    summ = f[x] + f[1-x] + val;
                    l = f[0];
                    r = f[1];
                    z = val;
                }
            };
    		func(0);
            func(1);
    	}
    	dp[i][0] = l;
    	dp[i][1] = r;
    	dp[i][2] = z;
    }
    cout << dp[n][0] + dp[n][1] + dp[n][2]<< endl;
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
