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
    int a, b, c;
    cin >> a >> b >> c;
    if (b > a && b > c) {
    	cout << "turned" << endl;
    	return;
    }
    if (b < a && b < c) {
    	cout << "turned" << endl;
    	return;
    }
    if (a < b && b < c) {
    	if (c - b > b - a) {
    		cout << "accelerated" << endl;
    	} else if (c - b == b - a) {
    		cout << "cruised" << endl;
    	} else if (c - b < b - a) {
    		cout << "braked" << endl;
    	}
    } else {
    	if (c - b < b - a) {
    		cout << "accelerated" << endl;
    	} else if (c - b == b - a) {
    		cout << "cruised" << endl;
    	} else if (c - b > b - a) {
    		cout << "braked" << endl;
    	}
    }
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
