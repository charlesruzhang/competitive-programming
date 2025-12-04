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
    int n, p, s;
    cin >> n >> p >> s;
    for (int i = 0; i < s; i++) {
    	int cnt; cin >> cnt;
    	int flag = 0;
    	for (int j = 0; j < cnt; j++) {
    		int x;
    		cin >> x;
    		if (x == p) {
    			flag = 1;
    		}
    	}
    	if (flag) {
    		cout << "KEEP" << endl;
    	} else {
    		cout << "REMOVE" << endl;
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
