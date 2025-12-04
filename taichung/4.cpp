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
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	map<int, int> ma;
	auto it = s.begin();
	int cnt = 0;
	while (it != s.end()) {
		ma[*it] = (++cnt);
		++it;
	}
	vi b = a;
	sort(a.begin(), a.end());
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			flag = 1;
			break;
		}
	}
	if (!flag ){
		cout << 0 << endl;
		return;
	}
	vi counter(cnt);
	vi first(cnt);
	for (int i = 0; i < n; i++) {
		int idx = ma[a[i]] - 1;
		if (!counter[idx]) first[idx] = i;
		counter[idx]++;
	}
	vi cur(cnt);
	for (int i = 0; i < cnt; i++) {
		cur[i] = first[i] + counter[i] - 1;
	}
	int idx = n - 1;
	ll ans = 1ll * n * n;
	int i = n - 1;
	vi c(n);
	int invalid = 0;
	while (i >= 0) {
		int x = ma[b[i]] - 1;
		c[cur[x]] = 1;
		if (cur[x] < i) {
			invalid++;
		}
		while (idx >= 0 && c[idx]) {
			idx--;
		}
		cur[x]--;
		ll tot = 1ll * (n - i) * (n - i);
		i--;
		if (!invalid) {
			while (i >= 0 && b[i] == a[i]) {
				int y = ma[b[i]] - 1;
				c[cur[y]] = 1;
				idx--;
				cur[y]--;
				i--;
			}
		}
		tot += 1ll * (idx + 1) * (idx + 1);
		ans = min(ans, tot);
		if (c[i] == 1) {
			invalid--;
		}
	}
	i = 0;
	idx = 0;
	vi d(n);
	invalid = 0;

	while (i < n) {
		int x = ma[b[i]] - 1;
		d[first[x]] = 1;
		if (first[x] > i) {
			invalid++;
		}
		while (idx < n && d[idx]) {
			idx++;
		}
		first[x]++;
		ll tot = 1ll * (i + 1) * (i + 1);
		i++;
		if (!invalid) {
			while (i < n && b[i] == a[i]) {
				int y = ma[b[i]] - 1;
				d[first[y]] = 1;
				idx++;
				first[y]++;
				i++;
			}
		}
		tot += 1ll * (n - idx) * (n - idx);
		ans = min(ans, tot);
		if (d[i] == 1) {
			invalid--;
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
