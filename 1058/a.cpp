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
int query (vi & a) {
	cout << "? " << a.size() << " ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    vi a;
    vi ans(2 * n);
    vi b;
    for (int i = 0; i < 2 * n; i++) {
    	a.push_back(i);
    	int z = query(a);
    	if (z) {
    		a.pop_back();
    		ans[i] = z;
    		b.push_back(i);
    	} 
    }
    for (int i = 0; i < 2 * n; i++) {
    	if (ans[i]) continue;
    	b.push_back(i);
    	int z = query(b);
    	ans[i] = z;
    	b.pop_back();
    }
    cout << "! ";
    for (int i = 0; i < 2 * n; i++) {
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
