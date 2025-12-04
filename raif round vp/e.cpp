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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll tot = 0;
    priority_queue<array<ll, 3>> pq;
    int C = n;
    auto get = [&] (int i, int cur) {
    	int z = a[i] / cur;
    	int y = a[i] % cur;
    	int x = cur - a[i] % cur;
    	return 1ll * y * (z + 1) * (z + 1) + 1ll * x * z * z; 
    };
    for (int i = 0; i < n; i++) {
    	tot += 1ll * a[i] * a[i];
    	ll F = get(i, 1);
    	ll G = get(i, 2);
    	pq.push({F - G, i, 2});
    }
    while (C < k) {
    	auto [val, i, cur] = pq.top();
    	pq.pop();
    	tot -= val;
    	C++;
    	ll F = get(i, cur);
    	ll G = get(i, cur+1);
    	pq.push({F - G, i, cur + 1});
    }
    cout << tot << endl;
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
