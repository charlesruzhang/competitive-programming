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
	int n, q, k;
	cin >> n >> q >> k;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pii> qrs(q);
	for (int i = 0; i < q; i++) {
		cin >> qrs[i].first >> qrs[i].second;
		qrs[i].first --;
		qrs[i].second --;
	}
	int X = sqrt(k);
	vi ans(q);
	vi cnt(n+1), cnt2(n+1);
	for (int i = 1; i <= X; i++) {
		for (int j = 0; j < n; j++) {
			cnt[j+1] = cnt[j] + (a[j] <= i);
			cnt2[j+1] = cnt2[j] + (a[j] > k / (i + 1));
		}
		for (int j = 0; j < q; j++) {
			auto [l, r] = qrs[j];
			int z = r - l + 1;
			int x = (cnt[r+1] - cnt[l]);
			int y = (cnt2[r+1] - cnt2[l]);
			ans[j] = max(ans[j], min((y - x + 1) / 2, z / 2 - x));
		}
	}
	for (int i = 0; i < q; i++) {
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
