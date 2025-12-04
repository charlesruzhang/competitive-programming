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
    set<pii> x, y;
    for (int i = 0; i < n; i++) {
    	x.insert({a[i], i});
    	y.insert({b[i], i});
    }
    // cout << "-- A = " << endl;
    // for (int i = 0; i < n; i++) {
    // 	cout << a[i] << " ";
    // }
    // cout << endl;
    // cout << "-- B = " << endl;
    // for (int i = 0; i < n; i++) {
    // 	cout << b[i] << " ";
    // }
    // cout << endl;
    // cout << "------" << endl;
    int l = 0; 
    int r = m - 1;
    auto check = [&] (int mid) {
    	int L = 0;
    	int R = n - 1;
    	//cout << "mid = " << mid << endl;
    	for (int i = 0; i < n; i++) {
			auto it = x.lower_bound({b[i] - mid, -1});
			auto it2 = x.upper_bound({b[i], n});
    		if (b[i] < mid) {
    			it = x.lower_bound({b[i] - mid + m, -1});
    		}
    		if (b[i] >= mid && it == x.end()) return false;
    		else if (it == x.end()) it = x.begin();
			auto [z, w] = *it;
			if (b[i] >= mid && z > b[i]) return false;
			else if ((b[i] + m - z) % m > mid) return false;
			if (it2 != x.begin()) {
				--it2;
			} else {
				it2 = x.end();
				--it2;
			}
			auto [z2, w2] = *it2;

			if (b[i] >= mid && z2 > b[i]) return false;
			else if ((b[i] + m - z2) % m > mid) return false;
			w -= i;
			w2 -= i;
			if (w < 0) w += n;
			if (w2 < 0) w2 += n;
			if (R < L) R += n;
			if (w < L) w += n;
			if (w2 < L) w2 += n;
			if (L <= w && w <= R && R <= w2) {
				L = w;
			} else if (L <= w && w <= w2 && w2 <= R) {
				L = w;
				R = w2;
			} else if (L <= R && R <= w && w <= w2) {
				return false;
			} else if (L <= R && R <= w2 && w2 <= w) {
				continue;
			} else if (L <= w2 && w2 <= R && R <= w) {
				R = w2;
			} else if (L <= w2 && w2 <= w && w <= R) {
				assert(false);
			}
			L = L % n;
			R = R % n;
			//cout << i << " " << w - i << " " << w2 - i << endl;
		
    	}
    	//cout << mid << " " << L << " " << R << endl;
    	//cout << endl;
    	return true;
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
