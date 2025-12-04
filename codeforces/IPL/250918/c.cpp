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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int m;
    cin >> m;
    vi b(m);
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	while (j < m && b[j] + 1 < a[i]) {
    		j++;
    	}
    	if (j < m && abs(a[i] - b[j]) <= 1) {
    		cnt++;
    		j++;
    	}
    }
    cout << cnt << endl;
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
