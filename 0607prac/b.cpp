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
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi vec(26);
    for (int i = 0; i < n; i++) {
    	vec[s[i] - 'a'] ++;
    }
    int tot = 0;
    for (int i = 0; i < 26; i++) {
    	if (vec[i] % 2 == 1) {
    		tot ++ ;
    	}
    }
    if ((n - k) % 2 == 1) tot--;
    if (tot <= k) cout << "YES" << endl;
    else cout << "NO" << endl;
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
