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
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    map<int, int> cnt1, cnt2;
    for (int i = 0; i < n; i++) {
    	int z = a[i] % k;
    	if (z > k / 2) {
    		z = k - z;
    	}
    	cnt1[z]++;
    }
    for (int i = 0; i < n; i++) {
    	int z = b[i] % k;
    	if (z > k / 2) {
    		z = k - z;
    	}
    	cnt2[z]++;
    }
    auto it = cnt1.begin();
    while (it != cnt1.end()) {
    	auto [x, y] = *it;
    	if (cnt2[x] != y) {
    		cout << "No" << endl;
    		return;
    	}
    	++it;
    }
    cout << "Yes" << endl;
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
