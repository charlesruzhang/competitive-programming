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
    vi a(n);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	b[i].first = a[i];
    	b[i].second = i;
    }
    DSU D(n);
    sort(b.begin(), b.end(), greater<>());
    ll maxx = *max_element(a.begin(), a.end());
    ll res = 0;
    vi done(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int idx = b[i].second;
    	done[idx] = 1;
    	int s = 0;
    	int t = 0;
    	if (idx && done[idx-1]) {
    		s = D.size[D.find(idx-1)];
    		D.unite(idx, idx-1);
    	}
    	if (idx != n-1 & done[idx+1]) {
    		t = D.size[D.find(idx+1)];
    		D.unite(idx, idx+1);
    	}
    	int u = D.size[D.find(idx)];
    	ans += (u + 1) / 2 - (s + 1) / 2 - (t + 1) / 2;
    	res = max(res, maxx + b[i].first + ans);
    }
    cout << res << endl;

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
