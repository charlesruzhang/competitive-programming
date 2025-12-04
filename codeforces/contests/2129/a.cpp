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
    vi a(n), b(n);
    vector<pii> c(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }
    vi ans;
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	int y = b[i];
    	int f = 0;
    	for (int j = 0; j < n; j++) {
    		if (i != j && a[j] <= x && b[j] >= y) {
    			f = 1;
    			break;
    		}
    	}
    	if (!f) {
    		ans.push_back(i+1);
    	}
    }
    cout << ans.size() << endl;
    for (int v : ans) {
    	cout << v << " ";
    }
    cout << endl;
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
