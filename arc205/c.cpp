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
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i][0] >> a[i][1];
    	a[i][2] = i;
    }
    sort(a.begin(), a.end());
    vi ans1, ans2;
    int maxx = -1;
    for (int i = 0; i < n; i++) {
    	if (a[i][1] < maxx) {
    		cout << "No" << endl;
    		return;
    	}
    	if (a[i][0] > a[i][1]) ans1.push_back(a[i][2]);
    	else ans2.push_back(a[i][2]);
    	maxx = a[i][1];
    }
    reverse(ans2.begin(), ans2.end());
    cout << "Yes" << endl;
    for (int i = 0; i < ans1.size(); i++) {
    	cout << ans1[i] + 1 << " ";
    }
    for (int i = 0; i < ans2.size(); i++) {
    	cout << ans2[i] + 1 << " ";
    }
    cout << endl;
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
