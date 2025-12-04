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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi d(n);
    vvi L(n);
    for (int i = 0; i < n; i++) {
    	cin >> d[i];
    	L[max(0, i - d[i])].push_back(i);
    }
    int l = 0; 
    int r = 1e9;
    auto check = [&] (int m) {
    	//cout << m << " " << l << " " << r << endl;
    	priority_queue<pii, vector<pii>, greater<>> pq;
    	for (int i = 0; i < n; i++) {
    		int cur = m;
    		if (pq.size() && pq.top().first < i) {
    			return false;
    		}
    		for (int j = 0; j < L[i].size(); j++) {
    			if (a[L[i][j]]) pq.push({d[L[i][j]] + L[i][j], a[L[i][j]]});
    		}
    		while (!pq.empty() && cur > 0) {
    			auto [x, y] = pq.top();
    			if (y <= cur) {
    				pq.pop();
    				cur -= y;
    			} else {
    				pq.pop();
    				pq.push({x, y - cur});
    				break;
    			}
    		}
    	}
    	if (pq.size()) return false;
    	return true;
    };
    while (l < r) {
    	int m = (l + r) / 2;
    	if (check(m)) {
    		r = m;
    	} else {
    		l = m + 1;
    	}
    }
    cout << l << endl;
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
