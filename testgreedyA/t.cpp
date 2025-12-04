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
    ofstream out("29.in");
    int N = 2e5;
    int k = 2;
    out << N << " " << k << endl;
    for (int i = 0; i < N; i++) {
    	if (i < N / 4) {
    		out << 1 << " " << (int)2e8 << endl;
    	} else if (i < (2 * N) / 4) {
    		out << (int) 1e8 << " " << (int) 4e8 << endl;
    	} else if (i < (3 * N) / 4) {
    		out << (int) 3e8 << " " << (int) 6e8 << endl;
    	} else {
    		out << 7 * (int) 5e7 << " " << (int) 8e8 << endl;
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
