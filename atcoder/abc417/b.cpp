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
    vi now = a;
    for (int i = 0; i < m; i++) {
    	vi nn;
    	int flag = 0;
    	for (int j = 0; j < now.size(); j++) {
    		if (flag == 0 && now[j] == b[i]) {
    			flag = 1;
    		} else {
    			nn.push_back(now[j]);
    		}
    	}
    	swap(nn, now);
    }
    for (int i = 0; i < now.size(); i++) {
    	cout << now[i] << " ";
    }
    cout << endl;
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
