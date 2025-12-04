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
    //ofstream out("hack.txt");
    cout << 1 << endl;
    int k = 630;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
    	cout << k - i << " ";
    	for (int j = 0; j < k - i - 1; j++) {
    		cout << 1 << " ";
    	}
    	for (int j = k - i - 1; j < k - i; j++) {
    		cout << 1;
    	}
    	cout << endl;
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
