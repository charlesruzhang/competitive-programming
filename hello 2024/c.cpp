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
    int ans = 0;
    int maxx = INF;
    int max2 = a[0];
    for (int i = 1; i < n; i++) {
    	if (a[i] > maxx) {
    		max2 = a[i];
    		swap(maxx, max2);
    		ans++;
    	} else if (a[i] <= max2) {
    		max2 = a[i];
    	} else {
    		maxx = a[i];
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
