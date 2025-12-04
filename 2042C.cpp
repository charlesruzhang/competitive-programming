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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    vi S;
    int tot = 0;
    for (int i = n - 1; i >= 1; i--) {
    	int z = s[i] - '0';
    	tot += ((z) ? 1 : -1);
    	if (tot > 0) {
    		S.push_back(tot);
    		//cnt = 0;
    	}
    }
    sort(S.begin(), S.end(), greater<>());
    ll summ = accumulate(S.begin(), S.end(), 0ll);
    if (summ < k) {
    	cout << -1 << endl;
    	return;
    }
    ll to = 0;
    for (int i = 0; i < S.size(); i++) {
    	to += S[i];
    	if (to >= k) {
    		cout << i + 2 << endl;
    		return;
    	}
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
