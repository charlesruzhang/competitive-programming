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
class DSU {
public:
    vector<int> parent, size, left, right;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        left.resize(n);
        right.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            left[i] = i;
            right[i] = i; 
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
            left[a] = min(left[a], left[b]);
            right[a] = max(right[a], right[b]);
        }
    }
};
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n);
    vi b(m);
    vector<pii> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.push_back({a[i], 1});
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    	s.push_back({b[i], 0});
    }
    sort(s.begin(), s.end());
    multiset<pii> t;
    for (int i = 1; i < n + m; i++) {
    	t.insert({s[i].first - s[i-1].first, i});
    }
    vi pref(n + m + 1);
    vl summ(n + m + 1);
    for (int i = 0; i < n + m; i++) {
    	pref[i+1] = pref[i] + s[i].second;
    	summ[i+1] = summ[i] + s[i].first;
    }
    t.insert({1e9+7, 0});
    DSU D(n+m);
    ll tot = accumulate(a.begin(), a.end(), 0ll);
    vector<pii> qrs(q);
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	qrs[i] = {x, i};
    }
    sort(qrs.begin(), qrs.end());
    int idx = 0;
    vl ans(q);
    while (idx < q) {
    	//cout << " jo " << endl;
    	while (t.size() && (*t.begin()).first <= qrs[idx].first) {
    		auto [x, y] = *t.begin();
    		//cout << x << " " << y << " " << idx << endl;
    		int lol = D.left[D.find(y-1)];
    		int lr = D.right[D.find(y-1)];

    		int cum = pref[lr + 1] - pref[lol];
    		ll cumsum = summ[lr + 1] - summ[lr + 1 - cum];

    		int rl = D.left[D.find(y)];
    		int rr = D.right[D.find(y)];


    		cum = pref[rr + 1] - pref[rl];
    		cumsum += summ[rr + 1] - summ[rr + 1 - cum];

    		tot -= cumsum;
    		D.unite(y, y - 1);

    		int l = D.left[D.find(y)];
    		int r = D.right[D.find(y)];


    		cum = pref[r + 1] - pref[l];
    		tot += summ[r + 1] - summ[r + 1 - cum];	
    		t.erase(t.begin());
    	}

    	ans[qrs[idx].second] = tot;
    	idx++;
    }
    for (int i = 0; i < q; i++) {
    	cout << ans[i] << endl;
    }
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
