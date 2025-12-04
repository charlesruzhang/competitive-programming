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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int cnt = 0;
    int last = -1;
    int first = -1;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (i && a[i] < a[i-1]) {
    		cnt++;
    		if (first == -1) {
    			first = i - 1;
    		}
    		last = i;
    	}
    }
    if (cnt % 2 == 0) {
    	if (a[first] + last - first > a[last]) {
    		cout << cnt / 2 + 1 << endl;
    	} else {
    		cout << cnt / 2 << endl;
    	}
    } else {
    	cout << (cnt + 1) / 2 << endl;
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
