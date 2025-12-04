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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int h = a[k-1];
    sort(a.begin(), a.end());
    int idx = 0;
    while (idx < n - 1 && a[idx] < h) {
    	idx++;
    }
    int T = 0;
    while (idx < n - 1) {
    	int t = a[idx + 1] - a[idx];
    	T += t;
    	if (T > a[idx]) {
    		cout << "NO" << endl;
    		return;
    	}
    	idx ++;
    }
    if (idx == n-1) {
    	cout << "YES" << endl;
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
