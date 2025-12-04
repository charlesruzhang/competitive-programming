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
const ll MAXX = 1e13;
const int INF = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vl pref(n + 1);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	pref[i + 1] = pref[i] + x;
    }
    vl a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    	a[i] *= 2;
    }
    sort(a.begin(), a.end());
    int j = 0;
    ll prev = -MAXX;
    ll next = a[0];
    ll ans = 0;
    for (int i = 0; i <= 200 * n; i++) {

    	if (j < m && a[j] == i) {
    		prev = a[j];
    		next = (j + 1 < m ? a[j + 1] : MAXX);
    		j++;
    		continue;
    	}
    	ll L = (prev < 0) ? 0 : (i + prev + 2) / 2;
    	ll R = (next > 1e10) ? 200 * (n - 1) : (i + next - 1) / 2;
    	L = (L + 199) / 200;
    	R /= 200;
    	//cout << i << " " << L << " " << R << endl;
    	ans = max(ans, pref[min((ll) n, R + 1)] - pref[L]);
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
