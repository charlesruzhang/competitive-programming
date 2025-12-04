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
    vvi facts(n + 1);
    for (int i = 1; i <= n; i++) {
    	for (int j = i; j <= n; j+=i) {
    		facts[j].push_back(i);
    	}
    }
    vi mark(n + 1);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		for (int x : facts[i + 1]) {
    			mark[x] = 1;
    		}
    	} else {
    		for (int x : facts[i + 1]) {
    			if (!mark[x]) {
    				ans += x;
    				break;
    			}
    		}
    	}
    }
    cout << ans << endl;
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
