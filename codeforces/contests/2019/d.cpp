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
    vi a(n);
    vvi d(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	d[a[i]].push_back(i);
    }
    vector<pii> res(n+1, pii(n+2,-1));
    int ansmax = n+1, ansmin = -1;
    for (int i = 1; i <= n; i++) {
    	if (d[i].size()) res[i] = pii(d[i][0], d[i].back());
    	res[i].first = min(res[i].first, res[i-1].first);

    	res[i].second = max(res[i].second, res[i-1].second);
    	int diff = res[i].second - res[i].first;
    	if (diff < 0) continue;
    	int diff2 = i - diff - 1;
    	ansmax = min(ansmax, min(n-1, res[i].second + diff2));
    	ansmin = max(ansmin, max(0, res[i].first - diff2));
    	if (diff >= i) {
    		cout << 0 << endl;
    		return;
    	} 
    }
    //if (ans < 0) cout << 0 << endl;
    cout << ansmax - ansmin + 1 << endl;
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
