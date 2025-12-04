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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pii> b(m);
    for (int i = 0; i < m; i++) {
    	cin >> b[i].second >> b[i].first;
    }
    sort(b.begin(), b.end(), greater<>());
    int j = 0;
    for (int i = 0; i < n; i++) {
    	a[i] = max(a[i], b[j].first);
    	b[j].second--;
    	if (b[j].second == 0) {
    		j++;
    	}
    	if (j == m) {
    		break;
    	}
    }
    ll summ = 0;
    for (int i = 0; i < n; i++) {
    	summ += a[i];
    }
    cout << summ << endl;
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
