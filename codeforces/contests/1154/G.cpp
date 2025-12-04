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
int x = 1e7;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vvi cnt(x+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]].push_back(i);
    }
    ll ans = 1e18;
    int y = -1, z = -1;
    for (int i = 1; i <= x; i++) {
    	int prev = -1;
    	for (int j = 1; j * i <= x; j++) {
    		int J = j * i;
    		if (cnt[J].size() && prev != -1) {
    			int idx = cnt[J][0];
    			ll zz = 1ll * j * a[prev];
    			if (ans > zz) {
    				ans = 1ll * j * a[prev];
    				y = idx;
    				z = prev;
    			}
    			break;
    		} else if (cnt[J].size() >= 2) {
    			int idx1 = cnt[J][0];
    			int idx2 = cnt[J][1];
    			if (ans > J) {
    				ans = J;
    				y = idx1;
    				z = idx2;
    			}
    			break;
    		} else if (cnt[J].size() == 1) {
    			prev = cnt[J][0];
    		}
    	}
    }
    if (z > y) swap(z, y);
    cout << z + 1 << " " << y + 1 << endl;
 
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
