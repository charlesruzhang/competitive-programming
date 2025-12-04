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
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi mark(n, INF);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
    	b[i].first = a[i];
    	b[i].second = i;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
    	if (mark[b[i].second] != INF) continue;
    	int j = b[i].second;
    	int z = j;
    	j--;
    	while (j >= 0 && mark[j] == INF && a[j] % a[z] == 0) {
    		mark[j] = a[z];
    		j--;
    	}
    	j = b[i].second;
    	while (j + 1 < n && mark[j] == INF && (a[j+1] % a[z] == 0)) {
    		mark[j] = a[z];
    		j++;
    	}
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
    	ans += min(p, mark[i]);
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
