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
    vl a(n);
    set<ll> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    if (s.size() < n) {
    	cout << "NO" << endl;
    	return;
    }
    for (int i = 2; i <= 50; i++) {
    	vi cnt(i);
    	for (int j = 0; j < n; j++) {
    		cnt[a[j] % i]++;
    	}
    	int minn = INF;
    	for (int j = 0; j < i; j++) {
    		minn = min(minn, cnt[j]);
    	}
    	if (minn >= 2) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    cout << "YES" << endl;
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
