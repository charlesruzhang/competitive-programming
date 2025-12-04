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
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
    	cin >> s[i];
    }
    if (s[0].size() != s[1].size()) {
    	cout << "NO" << endl;
    	return;
    }
    if (s[1].size() != s[2].size()) {
    	cout << "YES" << endl;
    	return;
    }
    int n = s[0].size();
    DSU D(26);
    for (int i = 0; i < n; i++) {
    	D.unite(s[0][i]-'a', s[1][i] - 'a');
    }
    for (int i = 0; i < n; i++) {
    	if (D.find(s[0][i] - 'a') != D.find(s[2][i] - 'a')) {
    		cout << "YES" << endl;
    		return;
    	}
    }
    cout << "NO" << endl;
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
