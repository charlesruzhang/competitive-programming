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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi mark(n);
    vector<pii> ans;
    for (int i = n - 1; i >= 1; i --) {
    	vvi cnt(i);
    	for (int j = 0; j < n; j++) {
    		if (mark[j]) continue;
    		cnt[a[j] % i].push_back(j);
    	}
    	for (int j = 0; j < i; j++) {
    		if (cnt[j].size() >= 2) {
    			ans.push_back({cnt[j][0], cnt[j][1]});
    			mark[cnt[j][0]]=1;
    			break;
    		}
    	}
    }
    cout << "YES" << endl;
    for (int i = 0; i < n - 1; i++) {
    	cout << ans[n - i - 2].first + 1 << " " << ans[n-i-2].second + 1 << endl;
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
