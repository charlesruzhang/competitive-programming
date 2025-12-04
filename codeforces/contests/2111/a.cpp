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
void solve() {
    int x;
    cin >> x;
    vi arr(3, x);
    int cnt = 0;
    while (1) {
    	sort(arr.begin(), arr.end());
    	if (!arr[2]) {
    		break;
    	}
    	int minn = arr[1];
    	arr[2] = minn / 2;
    	cnt++;
    }
    cout << cnt << endl;
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
