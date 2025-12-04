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
    int n, k;
    cin >> n >> k;
    int x = n;
    int cnt = 0;
    priority_queue<int> pq;
    vl counter(23);
    ll summ = 0;
    while (x) {
    	int y = x % 3;
    	counter[cnt] = y;
    	summ += y;
    	cnt++;
    	x /= 3;
    }
    if (summ > k) {
    	cout << -1 << endl;
    	return;
    }
    for (int i = 22; i >= 1; i--) {
    	if (counter[i]) {
    		int diff = k - summ;
    		if (counter[i] <= diff / 2) {
    			counter[i-1] += 3 * counter[i];
    			summ += 2 * counter[i];
    			counter[i] = 0;
    		} else {
    			counter[i-1] += (diff / 2) * 3;
    			counter[i] -= diff / 2;
    			summ += 2 * (diff / 2);
    		}
    	}
    }
    vl p(23);
    p[0] = 1;
    for (int i = 1; i <= 22; i++) {
    	p[i] = p[i-1] * 3;
    }
    ll ans = 0;
    for (int i = 0; i <= 22; i++) {
    	if (!i) ans += 1ll * counter[i] * p[i+1];
    	else ans += 1ll * counter[i] * (p[i+1] + i * p[i-1]);
    }
    cout << ans << endl;
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
