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
const ld EPS = 1e-9;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pii>> e(n);
    for (int i = 0; i < m; i++) {
    	int x, y, w;
    	cin >> x >> y >> w;
    	x--; y--;
    	e[x].push_back(pii(y,w));
    	e[y].push_back(pii(x,w));
    }
    vector<ld> prob(n, 0.0);
    vector<int> shop;
    int b = 0;
    for (int i = 0; i < k; i++) {
    	int x;
    	ld y;
    	cin >> x >> y;
    	x--;
    	shop.push_back(x);
    	prob[x] = y;
    	if (fabs(y - 1.0) < EPS) {
    		b = 1;
    	}
    }
    if (!b) {
    	cout << "impossible" << endl;
    	return;
    }
    vl sdist(n, MAXX);
    vi svis(n, 0);
    vl tdist(n, MAXX);
    vi tvis(n, 0);
    sdist[0] = 0;
    tdist[n-1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push(pair<ll, int>(0, 0));
    while (!pq.empty()) {
    	auto [y, x] = pq.top();
    	pq.pop();
 
        if (svis[x]) continue;
        svis[x] = 1;
 
    	for (auto [v, w] : e[x]) {
    		if (sdist[x] + w < sdist[v]) {
    			sdist[v] = sdist[x] + w;
    			pq.push(pair<ll, int>(sdist[v], v));
    		}
    	}
    }
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<>> pq2;
    pq2.push(pair<ll, int>(0, n-1));
    while (!pq2.empty()) {
    	auto [y, x] = pq2.top();
    	pq2.pop();
        
        if (tvis[x]) continue;
        tvis[x] = 1;
 
    	for (auto [v, w] : e[x]) {
    		if (tdist[x] + w < tdist[v]) {
    			tdist[v] = tdist[x] + w;
    			pq2.push(pair<ll, int>(tdist[v], v));
    		}
    	}
    }
    vector<pair<ll,int>> dist;
    for (int i = 0; i < k; i++) {
    	int sh = shop[i];
    	dist.push_back(pair<ll,int>(sdist[sh] + tdist[sh], sh)); 
    }
    sort(dist.begin(), dist.end());
    ld init = 1.0;
    int idx = 0;
    ld ans = 0;
    while (init > 0) {
    	ans += dist[idx].first * prob[dist[idx].second] * init;
    	init *= (1 - prob[dist[idx].second]);
    	
        idx++;
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
