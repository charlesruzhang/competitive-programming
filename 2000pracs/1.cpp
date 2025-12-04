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
    ll cnt = 0;
    vl ans(n);
    int prev = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '1') {
    		prev = i;
    		ans[i] = cnt + 1;
    		cnt = 0;
    	} else {
    		cnt += n - i - 1;
    		ans[prev] += i;
    	}
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
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
