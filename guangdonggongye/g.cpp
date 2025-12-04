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
    int r = n, c = n;

    int nn = n * n;
    int nnn = nn * n;

    vvi ans(2 * n, vi(2 * n));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            int val = 0;
            if (i == r) {
                val = (j < n ? n : 1);
            }
            if (j == c) {
                if (i < n) val += nnn;
                else if (i != r) val += nn;
            }
            ans[i][j] = val;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
    	for (int j = 0; j < 2 * n; j++) {
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
    }

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
