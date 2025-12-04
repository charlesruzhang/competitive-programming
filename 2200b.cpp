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
const ll MAXX = 1e18;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    map<ll, int> ma;
    ma[0] = 1;
    ma[n * 1ll * m - 1] = 2;
    int idx = 3;
    vector<vector<pair<int, ll>>> e(k * 2 + 5);
    vector<set<int>> lad(n);
    const int each = 1e6;
    for (int i = 0; i < k; i++) {
    	int a, b, c, d, h;
    	cin >> a >> b >> c >> d >> h;
    	a--; b--; c--; d--;
    	lad[a].insert(b);
    	lad[c].insert(d);
    	ll x = a*1ll*m+b;
    	ll y = c*1ll*m+d;
    	if (ma.find(x) == ma.end()) {
    		ma[x] = idx;
    		idx++;
    	}
    	if (ma.find(y) == ma.end()) {
    		ma[y] = idx;
    		idx++;
    	}
    	e[ma[x]].push_back(pair<int,ll>(ma[y], each * 1ll * (c - a) -h));
    }
    lad[0].insert(0);
    lad[n-1].insert(m-1);
    for (int i = 0; i < n; i++) {
    	int prev = -1;
    	for (auto it = lad[i].begin(); it != lad[i].end(); ++it) {
    		if (prev != -1) {
    			int now = *it;
    			ll dist = (now - prev) * 1ll * a[i];
    			e[ma[i*1ll*m+prev]].push_back(pair<int, ll>(ma[i*1ll*m+now], dist));
    			e[ma[i*1ll*m+now]].push_back(pair<int, ll>(ma[i*1ll*m+prev], dist));
    		}
    		prev = *it;
    	}
    }
    vector<ll> dist(idx+5, MAXX);
    dist[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(pair<ll, int>(0, 1));
    vector<bool> inQ(idx+5, 0);
    while (!pq.empty()) {
    	int u = pq.top().second;
    	pq.pop();
    	if (inQ[u]) continue;
    	inQ[u] = 1; 
    	for (auto [v, w]: e[u]) {
    		if (dist[u] != MAXX && dist[u] + w  < dist[v]) {
    			dist[v] = dist[u] + w;
    			pq.push(pair<ll, int>(dist[v], v));
    		}
    	}
    }
    if (dist[2] == MAXX) {
    	cout << "NO ESCAPE" << endl;
    } else {
    	cout << dist[2] - (n-1) * 1ll * each << endl;
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
