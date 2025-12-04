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
    int d, k;
    cin >> d >> k;
    ll target = 1ll * d * d;
    ll res = 0;
    for (int i = 0; i <= d + k; i+=k) {
    	if (2ll * i * i > target) {
    		res = i - k;
    		break;
    	}
    }
    if (res * res + (res + k) * (res+k) <= target) {
    	cout <<"Ashish" << endl;
    } else {
    	cout <<"Utkarsh" << endl;
    }
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
