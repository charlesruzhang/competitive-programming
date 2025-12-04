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
    int n, q;
    cin >> n >> q;
    vi cnt(n);
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	if (x) {
    		cnt[x-1]++;
    		cout << x << " ";
    	} else {
    		int minn = 1e9;
    		int idx = -1;
    		for (int j = 0; j < n; j++) {
    			if (cnt[j] < minn) {
    				minn = cnt[j];
    				idx = j;
    			}
    		}
    		cnt[idx]++;
    		cout << idx + 1 << " ";
    	}
    }
    cout << endl;
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
