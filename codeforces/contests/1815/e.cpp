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
    vvi e(n);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[v].push_back(u);
    }
    vi visited(n);
    visited[0] = 1;
    queue<pii> q;
    q.push({1, 0});
    vector<pii> F(n);
    F[0] = {1, 0};
    for (int i = 0; i < n; i++) {
    	F[i].second = i;
    }
    while (!q.empty()) {
    	auto [cnt, x] = q.front();
    	q.pop();
    	for (int v: e[x]) {
    		if (!visited[v]) {
    			q.push({cnt + 1, v});
    			F[v].first = cnt + 1;
    			visited[v] = 1;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (!visited[i]) {
    		cout << "INFINITE" << endl;
    		return;
    	}
    }
    sort(F.begin(), F.end(), greater<>());
    vi ans;
    while (F.size()) {
    	vector<pii> E;
    	for (int i = 0; i < F.size(); i++) {
    		ans.push_back(F[i].second);
    		if (F[i].first > 1) E.push_back({F[i].first - 1, F[i].second});
    	}
    	swap(E, F);
    }
    cout << "FINITE" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] + 1 << " ";
    }
    cout << endl;
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
