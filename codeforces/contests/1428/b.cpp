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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi mark(n);
    int f1 = 1;
    int f2 = 1;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '-') {
    		mark[i] = mark[(i + 1) % n] = 1;
    	}
    	if (s[i] == '<') {
    		f1 = 0;
    	}
    	if (s[i] == '>') {
    		f2 = 0;
    	}
    }
    if (f1 || f2) {
    	cout << n << endl;
    	return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cnt += mark[i];
    }
    cout << cnt << endl;
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
