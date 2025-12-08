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
    string t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi cnt(26);
    for (int i = 0; i < n; i++) {
    	cnt[s[i] - 'a']--;
    }
    for (int i = 0; i < m; i++) {
    	cnt[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
    	if (cnt[i] < 0) {
    		cout << "Impossible" << endl;
    		return;
    	}
    }
    int j = 0;
    string ans;
    for (int i = 0; i < 26; i++) {
    	while (j < n && s[j] - 'a' <= i) {
    		ans += s[j];
    		j++;
    	}
    	for (int z = 0; z < cnt[i]; z++) {
    		ans += (char) (i + 'a');
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
