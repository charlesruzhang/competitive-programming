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
void solve(ofstream& out, int t) {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    set<pii> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i][2];
    	a[i][1] = i + 1;
    	s.insert({a[i][2], a[i][1]});
    }
    for (int i = 0; i < n; i++) {
    	cin >> a[i][0];
    }
    sort(a.begin(), a.end());
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
    	auto it = s.lower_bound({a[i][0], 0});
    	if (it == s.end() || it -> first != a[i][0] || a[i][0] < a[i][2]) {
			out << "Case #" << t << ": ";
			out << -1 << endl;
			return;
    	}
    	auto [x, y] = *it;
    	ans.push_back({a[i][1], y});
    }
	out << "Case #" << t << ": ";
	out << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		out << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream ofile("a.out");
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(ofile, i + 1);
    }
    return 0;
}
