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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'B') {
    		flag = 0;
    		break;
    	}
    }
    if (flag) {
    	for (int i = 0; i < q; i++) {
    		int x;
    		cin >> x;
    		cout << x << endl;
    	}
    	return;
    }
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	int cur = 0;
    	int cnt = 0;
    	while (x) {
    		x = (s[cur] == 'B' ? x / 2 : x - 1);
    		cur = (cur + 1) % n;
    		cnt++;
    	}
    	cout << cnt << endl;
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
