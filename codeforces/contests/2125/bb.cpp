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
    string t;
    int f = 1;
    for (int i = 0; i < s.size(); i++) {
    	if (f && s[i] == '.') {
    		t += 'o';
    		f = 0;
    	}  else if (s[i] == '#') {
    		t += '#';
    		f = 1;
    	} else {
    		t += '.';
    	}
    }
    cout << t << endl;
    return;
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
