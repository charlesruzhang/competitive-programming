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
    ll n;
    int k;
    cin >> n >> k;
    int INF = 1e9 + 7;
    if (k == 1) {
    	cout << (n % INF)<< endl;
    	return;
    }
    vi f(3);
    f[0] = 0;
    f[1] = 1;
    int idx = 2;
    vi vec;
    while (1) {
    	int z = idx % 3;
    	f[z] = (f[(z + 1) % 3] + f[(z + 2) % 3]) % k;
    	if (!f[z % 3]) {
    		vec.push_back(idx);
    	}
    	if (f[z % 3] == 1 && f[(z+2) % 3] == 0) {
    		idx--;
    		ll ans = (1ll * idx * ((n / vec.size()) % INF)) % (INF);
    		ll z = n % vec.size();
    		if (z) ans += vec[z-1];
    		ans = ans % INF;
    		cout << ans << endl;
    		return;
    	}
    	idx++;
    }  
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
