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
void solve() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    }
    sort(a.begin(), a.end());
    vi ans(n);
    ll summ = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
    	if (summ < a[i].first) {
    		summ += a[i].first;
    	}
    	while (j < n && summ >= a[j].first) {
    		if (j != i) {
    			summ += a[j].first;
    		}
    		j++;
    	}
    	ans[a[i].second] = j - 1;
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
