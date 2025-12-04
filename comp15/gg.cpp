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
    int maxx = 0;
    vi cnt(n+1);
    int g = 0;
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	if (g && a[i] % g) {
    		maxx = i;
    	}
    	g = gcd(g, a[i]);
    	for (int j = 1; j * j <= x; j++) {
    		if (x % j == 0) {
    			cnt[j]++;
    			if (g % j != 0) {
    				maxx = max(maxx, cnt[j]);
    			}
    			if (j * j != x) {
    				cnt[x / j]++;
    				if (g % (x / j)) {
    					maxx = max(maxx, cnt[x/j]);
    				}
    			}
    		}
    	}
    	cout << maxx << " ";
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
