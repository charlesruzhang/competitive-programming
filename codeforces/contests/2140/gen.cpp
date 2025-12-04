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
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> r(1, 100000);
    ofstream out("10.in");
    int T = 1;
    out << T << endl;
    for (int t = 0; t < T; t++) {
    	int n = 199999;
    	out << n + 1 << " " << n + 1 << endl;
    	vi a(n);
    	for (int i = 0; i < n; i++) {
    		a[i] = i + 1;
    	}
    	shuffle(a.begin(), a.end(), rng);
    	vector<pii> ans;
    	for (int i = 1; i < n; i++) {
    		ans.push_back({a[i-1], a[i]});
    		//out << a[i-1] << " " << a[i] << endl;
    	}
    	ans.push_back({a[n-1], a[0]});
    	shuffle(ans.begin(), ans.end(), rng);
    	for (auto [u, v]: ans) {
    		out << u << " " << v << endl;
    	}   
    	out << 1 << " " << 200000 << endl;
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
