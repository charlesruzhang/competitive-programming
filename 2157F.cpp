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
    if (n == 4) {
    	cout << "4\n1 4\n3 1\n2 1\n3 1\n";
    	return;
    }
    int N = 64;
    vector<pii> ans;
    for (int j = 1; j < N; j++) {
    	int x = n / N * N + j;
    	if (x >= n) x -= N;
    	while (x > 0) {
    		ans.push_back({x, 1});
    		x -= N;
    	}
	}
	for (int j = 1; j < N; j++) {
    	int x = n / (N * N) * N * N + j * N;
    	if (x >= n) x -= N * N;
    	while (x > 0) {
    		ans.push_back({x, N});
    		x -= N * N;
    	}
	}
	int cur = N * N;
	while (cur <= n) {
		ans.push_back({cur, N * N});
		cur += N * N;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
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
