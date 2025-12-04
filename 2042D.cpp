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
    vi l(n), r(n);
    for (int i = 0; i < n; i++) {
    	cin >> l[i] >> r[i];
    }
    vi p1(n);
    iota(p1.begin(), p1.end(), 0);
    sort(p1.begin(), p1.end(), [&](int a, int b) {
    	if (l[a] == l[b]) {
    		return r[a] > r[b];
    	}
    	return l[a] < l[b];
    });

    vi p2(n);
    iota(p2.begin(), p2.end(), 0);
    sort(p2.begin(), p2.end(), [&](int a, int b) {
    	if (r[a] == r[b]) {
    		return l[a] < l[b];
    	}
    	return r[a] > r[b];
    });

    vector<array<int, 2>> ans(n);
    set<int> s1;
    for (int i = 0; i < n; i++) {
    	int z = p1[i];
    	if (i && l[p1[i-1]] == l[p1[i]] && r[p1[i-1]] == r[p1[i]]) {
    		ans[p1[i-1]] = ans[p1[i]] = {l[p1[i]], r[p1[i]]};
    		continue;
    	}
    	auto it = s1.lower_bound(r[z]);
    	if (it == s1.end()) {
    		ans[z][1] = r[z];
    	} else {
    		ans[z][1] = *it;
    	}
    	s1.insert(r[z]);
    }

    set<int, greater<>> s2;
    for (int i = 0; i < n; i++) {
    	int z = p2[i];
    	if (i && l[p2[i-1]] == l[p2[i]] && r[p2[i-1]] == r[p2[i]]) {
    		ans[p2[i-1]] = ans[p2[i]] = {l[p2[i]], r[p2[i]]};
    		continue;
    	}
    	auto it = s2.lower_bound(l[z]);
    	if (it == s2.end()) {
    		ans[z][0] = l[z];
    	} else {
    		ans[z][0] = *it;
    	}
    	s2.insert(l[z]);
    }

    for (int i = 0; i < n; i++) {
    	cout << ans[i][1] - ans[i][0] - r[i] + l[i] << " ";
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
