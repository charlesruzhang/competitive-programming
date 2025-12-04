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
    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (a[i] <= n) cnt[a[i]]++;
    }
    int mex = -1;
    for (int i = 0; i <= n; i++) {
    	if (!cnt[i]) {
    		mex = i;
    		break;
    	}
    }
    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
    	if (a[i] == mex + 1) {
    		l = min(l, i);
    		r = max(r, i);
    	}
    }
    if (mex == n) {
    	cout << "NO" << endl;
    	return;
    }
    if (l == n || l == r) {
    	cout << "YES" << endl;
    	return;
    }
    for (int i = l; i <= r; i++) {
    	if (a[i] < mex) {
    		cnt[a[i]]--;
    		if (cnt[a[i]] == 0) {
    			cout << "NO" << endl;
    			return;
    		}
    	}
    }
    cout << "YES" << endl;

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
