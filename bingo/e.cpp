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
    int n, k;
    cin >> n >> k;
    vector<string> vs(n);
    vector<vector<char>> a(n, vector<char>(k));
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    	for (int j = 0; j < k; j++) {
    		a[i][j] = (j % 2 == 0) ? vs[i][j] : ('Z' - vs[i][j] + 'A');
    	}
    }
    vector<pair<string, int>> ps;
    for (int i = 0; i < n; i++) {
    	string t;
    	for (char c:a[i]) {
    		t+=c;
    	}
    	//cout << t<< endl;
    	ps.push_back({t, i});
    }
    sort(ps.begin(), ps.end());
    for (int i = 0; i < n; i++) {
    	cout << ps[i].second + 1<< " ";
    }
    cout << endl;
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
