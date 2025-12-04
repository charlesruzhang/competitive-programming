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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int now = -1;
    ll summ = 0;
    for (int i = 0; i < n; i++) {
    	summ += a[i];
    	if (summ > x) {
    		now = i;
    		break;
    	}
    }
    if (now == -1) {
    	cout << 1ll * n * (n + 1) / 2 << endl;
    	return;
    }
    vl cnt(n);
    cnt[now]++;
    for (int i = 1; i < n; i++) {
    	summ -= a[i-1];
    	while (now < n - 1 && summ <= x) {
    		now++;
    		summ += a[now];
    	}
    	if (summ > x) {
    		cnt[now] += (cnt[i-1] + 1);
    	}
    }
    for (int i = 0; i < n; i++) {
    	//cout << i << " , " << cnt[i] << endl;
    }
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	tot += cnt[i];
    }
    cout << 1ll * n * (n + 1) / 2 - tot << endl;
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
