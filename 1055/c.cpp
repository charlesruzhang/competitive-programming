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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi cnt(n+1), cnt2(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[i+1] = cnt[i] + (a[i] == 0);
    	cnt2[i+1] = cnt2[i] + (a[i] == 1);
    }
    vi xx(n+1), yy(n+1);
    for (int i = 1; i < n; i++) {
    	xx[i+1] = xx[i] + ((a[i] == 1 && a[i-1] == 0) ? 1 : 0);
    	yy[i+1] = yy[i] + ((a[i] == 0 && a[i-1] == 1) ? 1 : 0);
    }
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	if ((r - l + 1) % 3 || (cnt[r+1] - cnt[l]) % 3) {
    		cout << -1 << endl;
    		continue;
    	}
    	int ans = (r - l + 1) / 3;
    	int z1 = xx[r+1] - xx[l+1];
    	int z2 = yy[r+1] - yy[l+1];
    	if ((r - l + 1) % 2) {
    		cout << ans << endl;
    		continue;
    	}
    	int tot = (r - l + 1) / 2;
    	if (z1 == tot || z2 == tot) {
    		cout << ans + 1 << endl;
    		continue;
    	}
    	//cout << i << "? " << z1 << " " << z2 << endl;
    	cout << ans << endl;
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
