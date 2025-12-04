// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first >> a[i].second;
    }
    vector<pair<double, int>> st;
    st.push_back({0, 0});
    vector<double> L(n), R(n);
    for (int i = 1; i < n - 1; i++) {
    	while (st.size()) {
    		auto [y, z] = st.back();
    		auto [X, Y] = a[z];
    		auto [Z, W] = a[i];
    		double A = (Y - W) / ((double) X - Z);
    		if (A <= y) {
    			st.pop_back();
    		} else {
    			break;
    		}
    	}
    	auto [X, Y] = a[st.back().second];
    	auto [Z, W] = a[i];
    	L[i] = -((double) (X * W - Y * Z)) / (Y - W);
    	st.push_back({(Y - W) / ((double) X - Z), i});
    }
    vector<pair<double, int>> st2;
    st2.push_back({0, n - 1});
    for (int i = n - 2; i >= 1; i--) {
    	while (st2.size()) {
    		auto [y, z] = st2.back();
    		auto [X, Y] = a[z];
    		auto [Z, W] = a[i];
    		double A = (Y - W) / ((double) X - Z);
    		if (A >= y) {
    			st2.pop_back();
    		} else {
    			break;
    		}
    	}
    	auto [X, Y] = a[st2.back().second];
    	auto [Z, W] = a[i];
    	R[i] = -((double) (X * W - Y * Z)) / (Y - W);
    	st2.push_back({(Y - W) / ((double) X - Z), i});
    }
    double ans = 0;
    for (int i = 1; i < n - 1; i++) {
    	ans = max(ans, (R[i] - L[i]) * a[i].second / 2);
    }
    cout << setprecision(10) << ans << endl;
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
