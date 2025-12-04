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
    ll L;
    cin >> n >> m >> L;
    vl a(n+2);
    a[0] = L;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    a[n+1] = 0;
    vl c(m);
    for (int i = 0; i < m; i++) {
    	cin >> c[i];
    }
    ll start = 0;
    int dir = 1;
    vector<pll> v;
    for (int i = 1; i <= n + 1; i++) {
    	ll end = start + dir * (a[i-1] - a[i]);
    	if (dir == 1) {
    		v.push_back({start, 0});
    		v.push_back({end, 1});
    	} else {
    		v.push_back({start, 1});
    		v.push_back({end, 0});
    	}
    	start = end;
    	dir = -dir;
    }
    for (int i = 0; i < m; i++) {
    	v.push_back({c[i], -1});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    ll summ = 0;
    vl ans(m+1);
    int id = 0;
    for (int i = 0; i < v.size(); i++) {
    	auto [x, y] = v[i];
    	//cout << x << " ??? " << y << endl;
    	if (y == -1) {
    		ans[id++] += cnt * x - summ;
    		ans[id] -= cnt*x;
    		summ = 0;
    	} else if (y == 0) {
    		cnt ++;
    		summ += x;
    	} else {
    		cnt --;
    		summ -= x;
    	}
    }
    ans[m] += -summ; 
    for (int i = 0; i <= m; i++) {
    	cout << ans[i] << " ";
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
