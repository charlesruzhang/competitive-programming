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
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    }
    vi cnt(n+1);
    sort(a.begin(), a.end(), greater<>());
    for (int i = 2; i <= n; i++) {
    	int flag = 0;
    	for (int j = 2; 1ll * j * j <= i; j++) {
    		if (i % j == 0) {
    			flag = 1;
    			cnt[i] = cnt[i / j] + 1;
    			break;
    		}
    	}
    	if (!flag) cnt[i] = 1;
    }
    int x = *max_element(cnt.begin(), cnt.end());
    if (x >= m) {
    	cout << -1 << endl;
    	return;
    } 
    for (int i = 0; i < n; i++) {
    	cout << a[cnt[i+1]] << " ";
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
