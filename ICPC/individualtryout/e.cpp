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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi known(n);
    vi sol(n);
    for (int i = 0; i < n; i++) {
    	sol[i] = s[i] == 'L' ? 0 : 1;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
    	int flag = 1;
    	for (int j = 0; j < n; j++) {
    		int prev = (j == 0 ? 0 : sol[j-1] ^ 1);
    		if (!known[j]) {
    			if (prev != sol[j]) {
    				flag = 0;
    				known[j] = 1;
    				break;
    			}
    		}
    		known[j] = 1;
    	}
    	ans += flag;
    }
    cout << ans << endl;
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
