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
    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    vector<pii> st;
    for (int i = 0; i < n; i++) {
    	while (st.size() && st.back().first < a[i]) {
    		st.pop_back();
    	}
    	st.push_back({a[i], i});
    }
    sort(b.begin(), b.end(), greater<>());
    vi ans;
    int j = 0;
    int l = 0;
    int z = 0;
    while (1) {
    	while (l < st.size() && j < st[l].second) {
    		ans.push_back(a[j]);
    		j++;
    	}
    	while (z < m && (l >= st.size() || b[z] >= st[l].first)) {
    		ans.push_back(b[z]);
    		z++;
    	}
    	if (l < st.size()) ans.push_back(st[l].first);
    	l++;
    	j++;
    	if (l >= st.size() && z >= m) {
    		break;
    	}
    }
    assert(ans.size() == n + m);
    for (int i = 0; i < n + m; i++) {
    	cout << ans[i] << " ";
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
