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
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
    	pq.push(a[i]);
    }
    sort(a.begin(), a.end(), greater<>());
    ll maxx = a[0];
    ll tot = accumulate(a.begin(), a.end(), 0ll);
    for (int i = n; i >= 1; i--) {
    	//cout << m << "?" << tries << endl;
    	if (maxx * i - tot < 0) {
    		if (((i - tot % i) % i) <= k) {
    			cout << i << endl;
    			return;
			}
			continue;
    	}
    	if (maxx * i - tot <= k) {
    		cout << i << endl;
    		return;
    	}
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
