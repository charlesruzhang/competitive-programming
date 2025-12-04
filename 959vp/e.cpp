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
    int k;
    cin >> k;
    vi X(k);
    for (int i = 0; i < k; i++) {
    	int n;
    	cin >> n;
    	vi p(n);
    	for (int j = 1; j < n; j++) {
    		cin >> p[j];
    	}
    	X[i] = n;
    }
    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
    	pq.push(X[i]);
    }
    int ans = 0;
    for (int i = 28; i >= 0; i--) {
    	if (ans & (1 << i)) continue;
    	if (pq.empty()) break;
    	if (pq.top() >= (1 << i)) {
    		int z = 31 - __builtin_clz(pq.top());
    		if (z == i) {
    			ans |= (1 << i);
    			int x = pq.top() - (1 << i);
    			pq.pop();
    			pq.push(x);
    		} else {
    			ans |= ((1 << (i + 1)) - 1);
    			break;
    		}
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
