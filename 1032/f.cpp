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
void solve() {
    int n, x;
    ll s;
    cin >> n >> s >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll tot = s;
    map<ll, ll> ma;
    ll offset = 0;
    ll ans = 0;
    ma[0] = 1;
    for (int i = 0; i < n; i++) {
    	if (a[i] > x) {
    		map<ll, ll> nma;
    		nma[0] = 1;
    		swap(ma, nma);
    		offset = 0;
    	} else {
    		offset += a[i];
    		ans += ma[offset - s];
    		ma[offset]++;
    	}
    }
    //cout << "??" << ans << endl;
    map<ll, ll> ma2;
    ma2[0] = 1;
    offset = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] >= x) {
    		map<ll, ll> nma;
    		nma[0] = 1;
    		swap(ma2, nma);
    		offset = 0;
    	} else {
    		offset += a[i];
    		ans -= ma2[offset - s];
    		ma2[offset]++;
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
