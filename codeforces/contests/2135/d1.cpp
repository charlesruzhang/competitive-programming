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
    vi a(1e5, 1);
    int res = query(1e5, a);
    if (res == 1) {
    	cout << "! " << 100000 << endl;
    	return;
    } 
    int low = 1e5+1;
    int high = 0;
    for (int i = 1; i <= 1e5; i++) {
    	if ((99999 / i) + 1 == res) {
    		low = min(low, i);
    		high = max(high, i);
    	} 
    }
    if (low >= high) {
    	cout << "! " << low << endl;
    	return;
    }
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
