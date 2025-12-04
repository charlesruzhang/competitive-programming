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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i =0 ; i < n; i++) {
    	cin>> a[i];
    }
    int last = n;
    for (int i = n - 1; i >= 0; i --) {
    	if (a[i] == 1) {
    		last = i;
    		break;
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] == 1) {
    		if (k >= last - i + 1) {
    			cout << "YES" << endl;
    		} else {
    			cout << "NO" << endl;
    		}
    		return;
    	}
    }
    cout << "YES" << endl;
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
