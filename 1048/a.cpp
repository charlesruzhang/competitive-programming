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
    ll x;
    cin >> k >> x;
    k++;
    ll y = (1ll << k) - x;
    vi ans;
    while (x != y) {
    	if (x < y) {
    		y -= x;
    		x += x;
    		ans.push_back(1);
    	} else {
    		x -= y;
    		y += y;
    		ans.push_back(2);
    	}
    	//cout << x << " " << y << endl;
    }
    reverse(ans.begin(), ans.end());
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
