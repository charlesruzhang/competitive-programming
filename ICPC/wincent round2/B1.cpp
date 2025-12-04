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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    ofstream out("Bt.out");
    while (t--) {
    	ll n;
    	cin >> n;
    	if (n == 1) {
    		out << 3 << endl;
    		continue;
    	}
    	if (n == 2) {
    		out << -1 << endl;
    		continue;
    	}
    	int d = floor(sqrt(floor(sqrt(n))));
    	int done = 0;
    	for (int i = 3; i <= d; i++) {
    		ll cur = n;
    		int flag = 1;
    		while (cur) {
    			int rem = cur % i;
    			cur /= i;
    			if (rem >= 2) {
    				flag = 0;
    				break;
    			} 
    		}
    		if (flag) {
    			out << i << endl;
    			done = 1;
    			break;
    		}
    	}
    	if (!done) {
    		for (int i = 15; i >= 2; i--) {
    			vi vec(4);
    			for (int j = 0; j < 4; j++) {
    				vec[j] = (i & (1 << (3 - j))) ? 1 : 0;
    			}
    			ll l = 3;
    			ll r = n;
    			auto f = [&] (ll mid, ll tar) {
    				__int128 tot = 0;
    				for (int j = 0; j < 4; j++) {
    					__int128 cur = 1;
    					if (vec[j]) {
    						for (int k = 0; k < (3 - j); k++) {
    							cur *= mid;
    							if (cur > tar) return true;
    						}
    						tot += cur;
    					}
    				}
    				return tot > tar;
    			};
    			while (l < r) {
    				ll mid = (l + r + 1) / 2;
    				if (f(mid, n)) {
    					r = mid - 1;
    				} else {
    					l = mid;
    				}
    			}
    			if (f(l, n - 1) && !f(l, n)) {
    				out << l << "\n";
    				done = 1;
    				break;
    			} 
    		}
    		assert(done);
    	}
    }

    return 0;
}
