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
    vi a(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    vi b(m), c(m);
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> c[i];
    }
    vi V;
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 0; i < m; i++) {
    	if (c[i] > 0) pq.push({b[i], c[i]});
    	else V.push_back(b[i]);
    }
    int ans = 0;
    while (!pq.empty()) {
    	auto [B, C] = pq.top();
    	pq.pop();
    	auto it = s.lower_bound(B);
    	if (it == s.end()) {
    		break;
    	}
    	int z = *it;
    	ans++;
    	s.erase(it);
    	z = max(z, C);
    	s.insert(z);
    }
    sort(V.begin(), V.end());
    auto it = s.begin();
    for (int v: V) {
    	while (it != s.end() && *it < v) {
    		++it;
    	}
    	if (it == s.end()) break;
    	++it;
    	ans++;
    }
    cout << ans << endl;
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
