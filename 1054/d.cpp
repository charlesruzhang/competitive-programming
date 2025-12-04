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
    string s;
    cin >> s;
    vi pref(n+1);
    vi suff(n+1);
    vl pref2(n + 1), suff2(n + 1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + (s[i] == 'a');
    	pref2[i+1] = pref2[i] + (s[i] == 'a' ? i : 0);
    }
    for (int i = n - 1; i >= 0; i --) {
    	suff[i] = suff[i+1] + (s[i] == 'a');
    	suff2[i] = suff2[i+1] + (s[i] == 'a' ? i : 0);
    }
    ll ans = MAXX;
    for (int i = 0; i < n; i++) {
    	int l = pref[i];
    	int r = suff[i];
    	ll tot = 1ll * (i - 1 + i - l) * l / 2 - 1ll * (i + i + r - 1) * r / 2;
    	tot -= pref2[i];
    	tot += suff2[i];
    	ans = min(ans, tot);
    	//cout << i << " " << tot << endl;
    }
    for (int i = 0; i < n; i++) {
    	int l = i - pref[i];
    	int r = n - i - suff[i];
    	ll tot = 1ll * (i - 1 + i - l) * l / 2 - 1ll * (i + i + r - 1) * r / 2;
    	//cout << "? " <<  1ll * (n + i - 1) * (n - i) / 2 << endl;
    	tot -= 1ll * i * (i - 1) / 2 - pref2[i];
    	tot += 1ll * (n + i - 1) * (n - i) / 2 - suff2[i];
    	ans = min(ans, tot);
    	//cout << i << " " << tot << endl;
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
