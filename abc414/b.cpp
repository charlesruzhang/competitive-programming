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
    int n;
    cin >> n;
    string s;
    int tot = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
    	char c; int l;
    	cin >> c >> l;
    	int cnt = 0;
    	while (tot < 100 && cnt < l) {
    		s += c;
    		cnt ++;
    		tot++;
    	}
    	if (tot >= 100 && cnt < l) {
    		flag = 1;
    	}
    }
    if (flag) {
    	cout << "Too Long" << endl;
    } else {
    	cout << s << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
