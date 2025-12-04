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
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> vs(n);
    for (int i = 0; i < n; i++) {
    	cin >> vs[i];
    }
    int tot = 1;
    for (int i = 0; i < k; i++) {
    	tot *= n;
    }
    vector<string> vs2(tot);
    for (int i = 0; i < k; i++) {
		for (int z = 0; z < tot; z++) {
			int y = z;
			vi v;
			for (int xx = 0; xx < k; xx++) {
				v.push_back(y % n);
				y /= n;
			}
			reverse(v.begin(), v.end());
			vs2[z] += vs[v[i]];
		}
    }
    sort(vs2.begin(), vs2.end());
    cout << vs2[x-1] << endl;
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
