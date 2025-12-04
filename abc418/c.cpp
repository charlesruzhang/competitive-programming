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
    sort(a.begin(), a.end(), greater<>());
    int maxx = *max_element(a.begin(), a.end());
    int j = 0;
    vi counter(1e6+1);
    int cnt = 0;
    for (int i = 1e6; i >= 0; i--) {
    	while (j < n && a[j] == i) {
    		cnt++;
    		j++;
    	}
    	counter[i] = cnt;
    }
    vl tot(1e6+1);
    for (int i = 1; i <= 1e6; i++) {
    	tot[i] = tot[i-1] + counter[i];
    }
    while (q--) {
    	int b;
    	cin >> b;
    	if (b > maxx) cout << -1 << endl;
    	else cout << tot[b-1] + 1 << endl;
    }
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
