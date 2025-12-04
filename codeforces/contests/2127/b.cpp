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
    int n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;
    int l = k;
    int r = k;
    for (int i = k; i >= 1; i--) {
    	if (s[i-1] == '.') {
    		l = i - 1;
    	} else {
    		break;
    	}
    }
    for (int i = k; i < n - 1; i++) {
    	if (s[i+1] == '.') {
    		r = i + 1;
    	} else {
    		break;
    	}
    }
    int x = l + 1;
    int y = n - r;
    cout << max(min(k + 1, y), min(n - k, x)) << endl;  
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
