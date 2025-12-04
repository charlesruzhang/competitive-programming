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
    int p, s;
    cin >> p >> s;
    int g = gcd(p, s);
    p /= g;
    s /= g;
    if (p % 2 == 1) {
    	p *= 2;
    	s *= 2;
    }
    if (p > 2 * s + 2) {
    	cout << -1 << endl;
    	return;
    }
    int fact = (16 * s - 1) / (p * p) + 1;
    int P = fact * p;
    int S = fact * s;
    if (P % 4 != 0) {
    	P *= 2;
    	S *= 2;
    }
    int diff = P * P / 16 - S;
    int N = P / 4 - 1;
    if (N == 0) {
    	cout << 1 << endl;
    	cout << 0 << " " << 0 << endl;
    	return;
    }
    if (P > 2 * S + 2) {
    	P /= 2;
    	S /= 2;
    	assert(P == 2 * S + 2);
    	cout << S << endl;
    	for (int i = 0; i < S; i++) {
    		cout << 0 << " " << i << endl;
    	}
    	return;
    }
    diff = N * N - diff;
    int y = diff % N;
    int x = diff / N;
    vector<pii> ans;
    for (int i = 0; i < N; i++) {
    	ans.push_back({0, i});
    }
    for (int i = 0; i <= N; i++) {
    	ans.push_back({i, N});
    }
    for (int i = 0; i < x; i++) {
    	for (int j = 0; j < N; j++) {
    		ans.push_back({i + 1, j});
    	}
    }
    for (int i = 0; i < y; i++) {
    	ans.push_back({x + 1, N - 1 - i});
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
