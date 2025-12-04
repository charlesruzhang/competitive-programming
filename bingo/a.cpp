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
    string s;
    cin >> s;
    int n = s.size();
    int flag = 0;
    for (int i = 1; i < s.size(); i++) {
    	if (s[i-1] != s[i]) {
    		flag = 1;
    	}
    }

    if (flag) {
    	string t = s;
    	reverse(s.begin(), s.end());
    	if (t == s) {
    		cout << n - 1 << endl;
    	} else {
    		cout << n << endl;
    	}
    } else {
    	cout << 0 << endl;
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
