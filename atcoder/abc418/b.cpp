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
    int l = -1, r = n;
    double maxx = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		if (s[i] == 't' && s[j] == 't') {
    			int cnt = 0;
    			for (int x = i + 1; x < j; x++) {
    				if (s[x] == 't') {
    					cnt++;
    				}
    			}
    			maxx = max(maxx, (double) cnt / (j - i - 1));
    		}
    	}
    }
    cout << setprecision(20) << maxx << endl;
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
