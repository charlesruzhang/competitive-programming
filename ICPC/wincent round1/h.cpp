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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream out("H.out");
    cin >> t;
    while (t--) {
        int n;
	    cin >> n;
	    vi val(n+1);
	    ll ans = 0;
	    for (int i = n; i >= 1; i--) {
	    	if (2 * i <= n) val[i]+=val[2 * i];
	    	if (2 * i + 1 <= n) val[i]+=val[2 * i + 1];
	    	val[i]++;
	    	//cout << i << " " << val[i] << endl;
	    }
	    for (int i = 1; i <= n; i++) {
	    	ans += 1ll * (val[i] + n) * (n - val[i] + 1) / 2;
	    }
	    int cur = 1;
	    int now = n;
	    //cout << ans << endl;
	    while (cur <= n) {
	    	ans -= 1ll * now * (n - cur);
	    	cur = 2 * cur + 1;
	    	now--;
	    }
	    out << ans << endl;
    }
    return 0;
}
