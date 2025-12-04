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
   	vi a(n), b(n);
   	int tot = 0;
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   		tot += (a[i] == 1) ? 1 : 0;
   	}
   	int tot2 = 0;
   	for (int i = 0; i < n; i++) {
   		cin >> b[i];
   		tot2 += (b[i] == 1) ? 1 : 0;
   	}
   	if (tot != tot2) {
   		cout << "No" << endl;
   		return;
   	}
   	if (tot >= 4) {
   		cout << "Yes" << endl;
   		return;
   	}
   	if (tot <= 1) {
   		if (a == b) {
   			cout << "Yes" << endl;
   		} else {
   			cout << "No" << endl;	
   		} 
   		return;
   	}
   	if (tot == 2) {
   		if (a == b) {
   			cout << "Yes" << endl;
   			return;
   		}
   		if (a[0] && a[1]) {
   			cout << "No" << endl;
   		} else if (b[0] && b[1]) {
   			cout << "No" << endl;
   		} else if (a[n-1] && a[n-2]) {
   			cout << "No" << endl;
   		} else if (b[n-1] && b[n-2]) {
			cout << "No" << endl;
   		} else {
   			cout << "Yes" << endl;
   		}
   		return;
   	}
   	if (tot == 3) {
   		if (a == b) {
   			cout << "Yes" << endl;
   			return;
   		}
   		if (a[0] && a[1] && a[2]) {
   			cout << "No" << endl;
   		} else if (b[0] && b[1] && b[2]) {
   			cout << "No" << endl;
   		} else if (a[n-1] && a[n-2] && a[n-3]) {
   			cout << "No" << endl;
   		} else if (b[n-1] && b[n-2] && b[n-3]) {
			cout << "No" << endl;
   		} else {
   			cout << "Yes" << endl;
   		}
   		return;
   	}

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
