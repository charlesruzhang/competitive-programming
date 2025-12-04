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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (!a[i]) tot++;
    }
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    if (abs(summ) > k * 1ll *  tot) {
    	cout << - 1 << endl;
    	return;
    }
    ll cur = 0;
    ll minn = 0, maxx = 0;
    ll min2 = 0, max2 = 0;
    int used = 0;
    for (int i = 0; i < n; i++) {
    	cur += a[i];
    	minn = min(minn, cur);
    	maxx = max(maxx, cur);
    	if (!a[i]) {
    		ll diff = summ + (tot - used - 1) * k;
    		ll diff2 = summ - (tot - used - 1) * k;
    		minn = min(minn, cur - diff);
    		maxx = max(maxx, cur - diff2);
    		used++;
    	}
    }
    cout << maxx - minn + 1 << endl;
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
