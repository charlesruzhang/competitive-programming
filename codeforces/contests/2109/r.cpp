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
    ll k;
    cin >> k;
    vi vec;
    while (k > 0) {
    	vec.push_back(k % 9);
    	k /= 9;
    }
    ll cur = 0;
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
    	cur = 10 * cur + vec[i];
    }

    for (int i = 0; i < vec.size(); i++) {
    	//cout << vec[i] << " ";
    	if (vec[i] >= 4) {
    		cur += pow(10, vec.size() - 1 - i);
    	}
    }
    //cout << endl;
    cout << cur << endl;
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
