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
    vi cnt(n + 1, -1);
    for (int i = 0; i < n; i++) {
    	if (a[i] != -1) {
    		if (cnt[a[i]] != -1) {
    			cout << "No" << endl;
    			return;
    		}
    		cnt[a[i]] = i;
    	}
    }
    int cur = 1;
    for (int i = 0; i < n; i++) {
    	if (a[i] == -1) {
    		while (cnt[cur] != -1) {
    			cur++;
    		}
    		a[i] = cur;
    		cur++;
    	}
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
    }
    cout << endl;
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
