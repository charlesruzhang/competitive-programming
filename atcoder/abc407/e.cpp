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
    cin >> n;
    vector<pii> a(2 * n);
    ll ans = 0;
    for (int i = 0; i < 2 * n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    	ans += a[i].first;
    }
    vector<pii> b = a;
    sort(b.begin(), b.end());
    vi mark(2 * n);
    for (int i = 0; i < n; i++) {
    	mark[b[i].second] = 1;
    	ans -= b[i].first;
    }
    int idx = n;
    priority_queue<int> pq;
    int tot = 0;
    for (int i = 0; i < 2 * n; i++) {
    	if (mark[i]) {
    		pq.push(a[i].first);
    		tot--;
    	} else {
    		tot++;
    	}
    	if (tot < 0) {
    		int x = pq.top();
    		pq.pop();
    		while (idx < 2 * n && b[idx].second < i) {
    			idx++;
    		}
    		ans += (x - b[idx].first);
    		tot += 2;
    		mark[b[idx].second] = 1;
    		idx++;
    	}
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
