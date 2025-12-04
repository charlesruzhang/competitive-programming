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
const ll MAXX = 6e5+5;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int summ = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	summ += a[i];
    }
    summ = summ / 2 + 1;
    sort(a.begin(), a.end(), greater<>());
    vl arr(MAXX, 0);
    arr[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = max(summ - a[i], 0); j < summ; j++) {
    		ans += arr[j]; 
    	}
    	for (int j = summ-1; j >= a[i]; j--) {
    		arr[j] += arr[j-a[i]];
    	}
    }
    cout << ans << endl;
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
