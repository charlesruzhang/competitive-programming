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
	vi a(n), b(n);
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 	}   
 	for (int i = 0; i < n; i++) {
 		cin >> b[i];
 	}
 	ll summA = accumulate(a.begin(),a.end(), 0ll);

 	ll summB = accumulate(b.begin(),b.end(), 0ll);
 	ll diff = summA - summB;
 	vl v;
 	v.push_back(1e9);
 	for (int i = 1; i * 1ll * i <= diff; i++) {
 		if (diff % i == 0) {
 			v.push_back(i);
 			v.push_back(diff / i);
 		}
 	}
 	sort(b.begin(),b.end());
 	for (ll x: v) {
 		vi w;
 		int flag = 1;
 		for (int i = 0; i < n; i++) {
 			int y = a[i] % x;
 			w.push_back(y);
 		}
 		sort(w.begin(), w.end());
 		for (int i = 0; i < n; i++) {
 			if (w[i] != b[i]) {
 				flag = 0;
 				break;
 			}
 		}
 		if (flag) {
 			cout << x << endl;
 			return;
 		}
 	}
 	cout << -1 << endl;
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
