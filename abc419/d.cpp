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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<pii> v;
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	v.push_back({x, 0});
    	v.push_back({y+1, 1});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    string ans;
    int j = 0;
    for (int i = 1; i <= n; i++) {
    	while (j < v.size() && v[j].first == i) {
    		cnt += (v[j].second) ? -1 : 1; 
    		j++;
    	}
    	if (cnt % 2) {
    		ans += t[i-1];
    	} else {
    		ans += s[i-1];
    	}
    }
    cout << ans << endl;
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
