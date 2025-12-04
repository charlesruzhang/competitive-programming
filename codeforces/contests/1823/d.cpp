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
    vi a(k), b(k);
    for (int i = 0; i < k; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
    	cin >> b[i];
    	b[i] -= 3;
    }
    if (b[0] + 3 > a[0]) {
    	cout << "NO" << endl;
    	return;
    }
    string ans;
    string S = "abc";
    char c = 'd';
    int cur = 0;
    int T = 0;
    for (int i = 0; i < k; i++) {
    	int tot = (i ? a[i] - a[i-1] : a[i]);
    	int p = (i ? b[i] - b[i-1] : b[i]);
    	if (tot < p) {
    		cout << "NO" << endl;
    		return;
    	}
    	for (int j = 0; j < p; j++) {
    		ans += c;
    	}
    	for (int j = p; j < tot; j++) {
    		ans += S[T % 3];
    		T++;
    	}
    	c++;
    }
    cout << "YES" << endl;
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
