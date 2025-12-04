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
    vi a(n);
    map<int, int> cnt;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    	tot += a[i];
    }
    auto it = cnt.begin();
    priority_queue<pii> pq;
    while (it != cnt.end()) {
    	auto [x, y] = *it;
    	if (x % 2 == 1) pq.push({y, x});
    	++it;
    }
    ll x = 0;
    ll y = 0;
    int turn = 0;
    while (!pq.empty()) {
    	auto [u, val] = pq.top();
    	pq.pop();
    	tot -= u;
    	if (turn) {
    		y += u;
    	} else {
    		x += u;
    	}
    	turn ^= 1;
    }
    x += tot / 2;
    y += tot / 2;
    cout << x << " " << y << endl;
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
