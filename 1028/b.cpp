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
struct Node {
	Node* l;
	Node* r;
	int idx, val;
	Node (int id) {
		l = nullptr;
		r = nullptr;
		idx = id;
		val = -1;
	}
};
void solve() {
    int n, q;
    cin >> n >> q;
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vector<tuple<int, int,int>> qrs(q);
    for (int i = 0; i < q; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	x--; y--; z--;
    	qrs[i] = {x, y, z};
    }
    vector<vector<Node*>> v(n);
    int cnt = -1;
    vector<Node*> nodes;
    for (int i = 0; i < n; i++) {
    	Node * nnode = new Node(++cnt);
    	nodes.push_back(nnode);
    	v[i].push_back(nnode);
    }
    for (int i = 0; i < q; i++) {
    	auto [x, y, z] = qrs[i];
    	Node* nnode = new Node(++cnt);
    	nnode -> l = v[x].back();
    	nnode -> r = v[y].back();
    	v[z].push_back(nnode);
    	nodes.push_back(nnode);
    }
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++) {
    	v[i].back() -> val = b[i];
    	pq.push({b[i], v[i].back() -> idx});
    }
    vi vis(nodes.size());
    // for (int i = 0; i < nodes.size(); i++) {
    // 	cout << i << endl;
    // 	if (nodes[i] -> l == nullptr) cout << -1 << endl;
    // 	else cout << nodes[i] -> l -> idx << " " << nodes[i] -> r -> idx << endl;
    // }
    while (!pq.empty()) {
    	auto [x, y] = pq.top();
    	pq.pop();
    	if (vis[y]) continue;
    	vis[y] = 1;
    	Node * l = nodes[y] -> l;
    	Node * r = nodes[y] -> r;
    	int minn = 1e9;
    	if (l == nullptr) continue;
		if (l -> val == -1) l -> val = x;
		if (r -> val == -1) r -> val = x;
		if (l -> val < x) {
			cout << -1 << endl;
			return;
		}
		if (r -> val < x) {
			cout << -1 << endl;
			return;
		}
		if (min(l -> val, r -> val) > x) {
			cout << -1 << endl;
			return;
		}
		if (!vis[l->idx]) pq.push({l -> val, l -> idx});
		if (!vis[r->idx]) pq.push({r -> val, r -> idx});
    }
    for (int i = 0; i < n; i++) {
    	if (v[i][0] -> val != -1) cout << v[i][0] -> val << " ";
    	else cout << 1000000000<< " ";
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
