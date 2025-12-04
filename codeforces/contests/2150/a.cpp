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
    string s;
    cin >> s;
    vi a(m);
    set<int> S;
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    	S.insert(a[i]);
    }
    int cur = 1;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'A') {
    		cur++;
    		S.insert(cur);
    	} else {
    		int tmp = cur + 1;
    		while (S.find(tmp) != S.end()) {
    			tmp++;
    		}
    		S.insert(tmp);
    		tmp = tmp + 1;
    		while (S.find(tmp) != S.end()) {
    			tmp++;
    		}
    		cur = tmp;
    	}
    }
    auto it = S.begin();
    cout << S.size() << endl;
    while (it != S.end()) {
    	cout << (*it) << " ";
    	++it;
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
