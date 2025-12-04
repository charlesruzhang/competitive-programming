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

vvi facts(1e5+1);
void comp() {
	for (int i = 1; i <= 1e5; i++) {
		for (int j = i; j <= 1e5; j+=i) {
			facts[j].push_back(i);
		}
	}
}
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
	int flag = 0;
	vi cnt(k+1);
	vi xx(k+1);
	int j = 0;
	int ans = INF;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int z = 0; z < facts[a[i]].size(); z++) {
			int x = facts[a[i]][z];
			if (x > k) break;
			cnt[x]++;
			if (cnt[x] == 1) {
				tot++;
			}
		}
		while (tot == k) {
			ans = min(ans, a[i] - a[j]);
			for (int z = 0; z < facts[a[j]].size(); z++) {
				int x = facts[a[j]][z];
				if (x > k) break;
				cnt[x]--;
				if (cnt[x] == 0) {
					tot--;
				}
			}
			j++;
		}
	}
	if (ans == INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
