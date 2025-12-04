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
    cin >> n;
    vi a(n);
    vi pref(n + 1);
    vi pref2(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i] % 3 == 1) {
    		pref[i+1] = pref[i] + (a[i] % 3 == 1);
    	} else {
    		pref[i+1] = pref[i];
    	}
    	if (a[i] % 3 == 2) {
    		pref2[i+1] = pref2[i] + (a[i] % 3 == 2);
    	} else {
    		pref2[i+1] = pref2[i];
    	}
    }
    vvi cnt(3, vi(3));
    ll ans = 0;
    cnt[0][0] = 1;
    for (int i = 0; i < n; i++) {
    	int y = pref[i+1] % 3;
    	int z = pref2[i+1] % 3;
    	ans += cnt[y][(z + 2) % 3];
    	ans += cnt[(y + 2) % 3][z];
    	ans += cnt[y][z];
    	cnt[y][z]++;
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
