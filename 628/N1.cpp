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
int f(ll x) {
	int cnt = 0;
	while (x) {
		cnt += x % 10;
		x /= 10;
	}
	return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    ofstream out("N1.out");

    while (t--) {
	        
	    ll d;
	    cin >> d;
	    ll dd = d;
	    if (d == 0) {
	    	out << "0 0" << endl;
	    	continue;
	    }
	    if (d % 9 != 0) {
	    	out << "NONE" << endl;
	    	continue;
	    }
	    vi vec;
	    while (d) {
	    	vec.push_back(d % 10);
	    	d /= 10;
	    }
	    reverse(vec.begin(), vec.end());
	    vi ans(vec.size());
	    int cur = 0;
	    for (int i = 0; i < vec.size(); i++) {
	    	cur += vec[i];
	    	if (cur >= 9) {
	    		ans[i] = 9;
	    		cur -= 9;
	    	}
	    }
	    ll res = 0;
	    for (int i = 0; i < ans.size(); i++) {
	    	res = res * 10 + ans[i];
	    }
	    out << res << " " << res + dd << endl;
	    assert(f(res) == f(res + dd));
    }
    return 0;
}
