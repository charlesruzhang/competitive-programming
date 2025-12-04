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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int g = gcd(x,y );
    x /= g;
    y /= g;
    const int INF = 1e9;
    function <int(int)> f = [&] (int x) {
    	vi v;
	    for (int i = 1; i * i <= x; i++) {
	    	if (x % i == 0) {
	    		v.push_back(i);
	    		if (i * i != x) v.push_back(x/i);
	    	}
	    }
	    sort(v.begin(), v.end());
	    int cur = x;
	    int tot = 0;
	    vi val(v.size(), INF);
	    val[0] = 0;
	    unordered_map<int, int, custom_hash> ma;
	    for (int i = 0; i < v.size(); i++) {
	    	ma[v[i]] = i; 
	    }
	    for (int i = 1; i < v.size(); i++) {
	    	if (v[i] > k) continue;
	    	for (int j = 0; j < v.size(); j++) {
	    		if (x % 1ll * v[j] * v[i] != 0) continue;
	    		int z = ma[v[j] * v[i]];
	    		val[z] = min(val[z], val[j] + 1);
	    	}
	    }
	    return val[v.size()-1];
    };
    int z = f(x);
    int w = f(y);
    if (z == INF || w == INF) {
    	cout << -1 << endl;
    	return;
    }
    cout << z + w << endl;
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
