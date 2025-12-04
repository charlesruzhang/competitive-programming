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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    set<int> s;
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (int i = 0; i < n; i++) {
    	s.insert(i);
    	pq.push({a[i], i});
    }
    ll ans = 0;
    vi mark(n);
    while (!pq.empty()) {
    	if (s.size() == 1) break;
    	auto [x, u] = pq.top();
    	//cout << x << " " << u << endl;
    	pq.pop();
    	if (mark[u]) continue;
    	auto it = s.lower_bound(u);
    	++it;
    	int minn = 2e9 + 1;
    	if (it != s.end()) {
    		int v = *it;
    		if (a[u] == a[v]) {
    			s.erase(it);
    			mark[v] = 1;
    			pq.push({x + 1, u});
    			a[u] = x + 1;
    			continue;
    		} else {
    			minn = min(a[v], minn);
    		}
    	}
    	it = s.lower_bound(u);
    	if (it != s.begin()) {
    		--it;
    		int v = *it;
    		minn = min(a[v], minn);
    	}
    	ans += minn - x;
    	pq.push({minn, u});
    	a[u] = minn;
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
