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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	a[i] = m - a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l = 0; 
    int r = m - 1;
    auto check = [&] (int mid) {
    	vector<pii> L;
    	for (int i = 0; i < n; i++) {
    		int key = b[i] - mid;
    		if (b[i] < mid) key += m;
    		int w = int(lower_bound(a.begin(), a.end(), key) - a.begin());
    		if (b[i] >= mid && w == n) return false;
    		else if (w == n) w = 0;
			if (b[i] >= mid && a[w] > b[i]) return false;
			else if ((b[i] + m - a[w]) % m > mid) return false;

    		int w2 = int(upper_bound(a.begin(), a.end(), b[i]) - a.begin());
			if (w2) w2--; 
			else w2 = n - 1;

			if (b[i] >= mid && a[w2] > b[i]) return false;
			else if ((b[i] + m - a[w2]) % m > mid) return false;

			w -= i; w2 -= i;
			if (w < 0) w += n;
			if (w2 < 0) w2 += n;
			L.push_back({w, 0});
			if (w2 >= w) L.push_back({w2, 1});
			else {
				L.push_back({n - 1, 1});
				L.push_back({0, 0});
				L.push_back({w2, 1});
			}
    	}
    	int cur = 0;
    	vi diff(n), diff2(n);
    	for (int i = 0; i < L.size(); i++) {
    		auto [xx, yy] = L[i];
    		if (!yy) diff[xx]++;
    		else diff2[xx]++;
    	}
    	vi pref(n+1);
    	for (int i = 0; i < n; i++) {
    		pref[i+1] = pref[i] + diff[i];
    		if (pref[i+1] == n) return true;
    		pref[i+1] -= diff2[i];
    	}
    	return false;
    };
    while (l < r) {
    	int mid = (l + r) / 2;
    	if (check(mid)) r = mid;
    	else l = mid + 1;
    }
    cout << l << endl;
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
