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
    int maxx = 0;
    int idx = -1;
    int minn = INF;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (maxx < a[i]) {
    		maxx = a[i];
    		idx = i;
    	}
    	minn = min(a[i],minn);
    }
    if (minn == maxx) {
    	cout << -1 << endl;
    	return;
    }
    cout << idx + 1<< endl;
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
