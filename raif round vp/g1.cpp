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
    int k;
    cin >> k;
    vector<pll> a(6);
    for (int i = 0; i < 6; i++) {
    	cin >> a[i].first;
    	for (int j = 5; j > i; j--) {
    		a[i].first *= 10;
    	}
    	a[i].second = i;
    }
    int q; cin >> q;
    int x; cin >> x;
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
