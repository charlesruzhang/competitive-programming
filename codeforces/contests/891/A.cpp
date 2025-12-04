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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cnt++;
        }
    }
    if (cnt) {
        cout << n - cnt << endl;
        return;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
    	int G = 0;
        for (int j = i; j < n; j++) {
    		G = gcd(G, a[j]);
            if (G == 1) {
                ans = min(ans, j - i);
                break;
            }
    	}
    }
    if (ans == n) {
    	cout << -1 << endl;
    	return;
    }
    ans += n - 1;
    cout << ans << endl;
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
