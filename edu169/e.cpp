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
const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;
vi val(N+1);
void comp() {
	for (int i=2; i <= N; ++i) {
	    if (lp[i] == 0) {
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for (int j = 0; i * pr[j] <= N; ++j) {
	        lp[i * pr[j]] = pr[j];
	        if (pr[j] == lp[i]) {
	            break;
	        }
	    }
	}
	int cnt = 0;
	for (int z : pr) {
		val[z] = ++cnt;
	}
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int cnt = 0;
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	int z = lp[a[i]];
    	if (z == 2) continue;
    	if (a[i] == 1) tot ^= 1;
    	else tot ^= val[z];
    }
    if (tot) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
