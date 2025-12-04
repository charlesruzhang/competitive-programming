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
    ll n;
    cin >> n;

    ll x = n;

    while (1) {

    	ll y = x;

    	vi vec;
    	while (y > 0) {
    		if (y % 10) vec.push_back(y % 10);
    		y /= 10;
    	}

    	int flag = 0;
    	for (int z : vec) {
    		if (x % z) {
    			flag = 1;
    			break;
    		} 
    	}
    	if (!flag) {
    		cout << x << endl;
    		return;
    	}

    	x++;
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
