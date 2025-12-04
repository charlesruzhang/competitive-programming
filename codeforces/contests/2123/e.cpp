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
    int n;
    cin >> n;
    vi a(n);
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    vi ans;
    vector<pii> vec;
    int tot = 0;
    int tot2 = 0;
    for (int i = 0; i <= n; i++) {
    	if (cnt[i] == 0) break;
    	tot += cnt[i];
    	vec.push_back({cnt[i], 0});
    	vec.push_back({cnt[i] + (n - tot) + tot2 - 1, 1});
    	tot2 += cnt[i] - 1;
    	//cout << i << " " << cnt[i] << " " << cnt[i] + (n - tot) + tot2 << endl;
    }
    sort(vec.begin(), vec.end());
    int idx = 0;
    int id = 0;
    int now = 1;
    while (idx <= n) {
    	int np = now;
    	while (id < vec.size() && vec[id].first == idx) {
    		int diff = (vec[id].second == 1) ? -1 : 1;
    		now += diff;
    		np = max(np, now);
    		id++;
    	}
    	ans.push_back(np);
    	idx++;
    }
    assert(ans.size() == n+1);
    for (int i = 0; i <= n; i++) {
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
