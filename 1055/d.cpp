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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi pref(n+1);
    vi pref2(n+1);
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	int cnt = 0;
    	int cnt2 = 0;
    	while (x > 1) {
    		x = x + 1;
    		x /= 2;
    		cnt++;
    	}
    	x = a[i] - 1;
    	while (x > 1) {
    		x = x + 1;
    		x /= 2;
    		cnt2++;
    	}
    	if (a[i] == 2) {
    		cnt2 = 1;
    	}
    	pref[i+1] = pref[i] + cnt;
    	pref2[i+1] = pref2[i] + (cnt - cnt2);
    }
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int x = pref[r+1] - pref[l];
    	int y = pref2[r+1] - pref2[l];
    	cout << x - ((y + 1) / 2) << endl;
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
