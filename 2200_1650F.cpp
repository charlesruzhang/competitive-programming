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
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<tuple<ll, int, int>>> arr(n);
    for (int i = 0; i < m; i++) {
    	int e, t, p;
    	cin >> e >> t >> p;
    	e--;
    	arr[e].push_back(tuple<ll, int, int>(t, p, i+1));
    }
    ll cur = 0;
    vi ans;
    for (int i = 0; i < n; i++) {
    	vector<ll> mt(101, MAXX);
    	vector<vector<int>> seq(101);
    	mt[0] = 0;
    	for (auto [t, p, x] : arr[i]) {
    		for (int j = 99; j >= 0; j--) {
    			if (t + mt[j] < mt[min(100, p+j)]) {
    				mt[min(100, p+j)] = t + mt[j];
    				vi ans2 = seq[j];
    				ans2.push_back(x);
    				swap(ans2, seq[min(100, p+j)]);
    			}
    		}
    	}
    	cur += mt[100];
    	if (cur > a[i]) {
    		cout << -1 << endl;
    		return;
    	}
    	for (int x : seq[100]) {
    		ans.push_back(x);
    	}
    }
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
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
