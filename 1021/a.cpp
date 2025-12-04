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
    vi a(n);
    map<int, int> ma;
    for (int i = 0; i  < n;i++) {
    	cin >> a[i];
    	ma[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < a.size(); i++) {
    	if (ma[a[i]] >= 4) {
    		cout << "Yes" << endl;
    		return;
    	}
    	if (ma[a[i]] >= 2 && ma[a[i]+1] >= 2) {
    		cout << "Yes" << endl;
    		return;
    	}
    	if (ma[a[i]] >= 2) {
    		ma[a[i]+1]++;
    	}
    }
    cout << "No" << endl;
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
