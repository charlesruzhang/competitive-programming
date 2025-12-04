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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pii> co(26);
    for (int i = 0; i < 26; i++) {
    	co[i].second = i;
    }
    for (char c : s) {
    	co[c - 'a'].first++;
    }
    vector<char> v(n, 0);
    sort(co.begin(), co.end(), greater<>());
    int idx = 0; 
    for (int i = 0; i < 26; i++) {
    	int cur = idx;
    	while (co[i].first) {
    		while (v[cur]) {
    			cur++;
    		}
    		v[cur] = (char) ('a' + co[i].second);
    		co[i].first--;
    		cur+=3;
    		if (cur >= n) {
    			idx++;
    			cur = idx;
    		} 
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << v[i];
    }
    cout << endl;
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
