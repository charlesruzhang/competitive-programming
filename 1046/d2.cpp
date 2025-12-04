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
int query(int n, vi& a) {
	cout << "? " << n << " ";
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int x = 10;
    int sz = 12000;
    int y = 110;
    vi a(sz, y);
    int res = query(sz, a);
    if (res == 0) {
    	vi b(25000 - sz, 1);
    	int res2 = query(25000 - sz, b);
    	int low = 1e5+1;
	    int high = 0;
	    for (int i = 1; i <= y; i++) {
	    	if (((25000 - sz - 1) / i) + 1 == res2) {
	    		low = min(low, i);
	    		high = max(high, i);
	    	} 
	    }
	    assert(low == high);
		cout << "! " << low << endl;
		return;
    } 
    
    int low = 1e5+1;
    int high = 0;
    for (int i = y; i <= 1e5; i++) {
    	int j = i / y;
    	if (((sz - 1) / j) + 1 == res) {
    		low = min(low, i);
    		high = max(high, i);
    	} 
    }
    //cout << low << " " << high << endl;
    vi b;
    for (int i = low + 1; i <= high; i++) {
    	b.push_back(low);
    	b.push_back(i - low);
    }
    int res2 = query(b.size(), b);
    int extra = res2 - b.size() / 2;
    cout << "! " << high - extra << endl;
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
