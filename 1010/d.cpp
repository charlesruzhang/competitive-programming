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
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
     void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    set<int> s;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	s.insert(x);
    	maxx = max(maxx, x);
    }
    vi vec(s.size());
    int idx = 0;
    vi ma(maxx+1);
    for (int x : s) {
    	vec[idx] = x;
    	ma[x] = idx;
    	idx++;
    }
    n = vec.size();
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    for (int i = 0; i < n - 1; i++) {
    	pq.push({vec[i+1] % vec[i], i+1, i});
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 2 * vec[i], k; j <= maxx; j = k) {
    		auto it = s.lower_bound(j);
    		if (it == s.end()) break;
    		pq.push({*it % vec[i], i, ma[*it]});
    		k = (*it / vec[i] + 1) * vec[i];
    	}
    }
    int tot = 0;
    DSU D(n);
    ll ans = 0;
    while (!pq.empty() && tot < n - 1) {
    	auto [w, x, y] = pq.top();
    	pq.pop();
    	if (D.find(x) != D.find(y)) {
    		ans += w;
    		D.unite(x,y);
    		tot++;
    	}
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
