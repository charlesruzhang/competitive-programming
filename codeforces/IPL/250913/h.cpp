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
    vi cnt(1e4+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    int ans = 0;
    for (int i = 1, next; i <= 1e4; i = next) {
    	if (!cnt[i]) {
    		next = i + 1;
    		continue;
    	}
    	int j = i;
    	while (j <= 1e4 && cnt[j]) {
    		cnt[j]--;
    		j++;
    	}
    	ans++;
    	next = i;
    }
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
