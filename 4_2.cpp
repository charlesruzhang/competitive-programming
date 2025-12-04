#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long int
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
struct Q {
    int t, type, a, b, se, val;
    bool operator > (Q x) {
        if (t == x.t) return type > x.type; 
        return t > x.t;
    }
};
const int INF = 1e18 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    auto cmp = [](const Q &x, const Q &y) {
        if (x.t == y.t)
            return x.type > y.type;
        return x.t > y.t;
    };
    priority_queue<Q, vector<Q>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < m; i++) {
        int a, b, s, e;
        cin >> a >> b >> s >> e;
        a--; b--;
        pq.push({s, 1, a, b, e, 0});
    }
    vector<pii> dp(n, pii(INF, -1));
    dp[0] = pii(0, 0);
    int ans = INF;
    while (!pq.empty()) {
    	Q x = pq.top();
    	pq.pop();
    	if (x.type) {
    		if (dp[x.a].second == -1) continue;
    		pq.push({x.se, 0, x.a, x.b, x.t, dp[x.a].first + (x.t - dp[x.a].second) * (x.t - dp[x.a].second)});
    		
    	} else {
    		if (x.b == n - 1) {
    			ans = min(ans, x.val);
    		}
    		if (dp[x.b].first + (x.t - dp[x.b].second) * (x.t - dp[x.b].second) > x.val) {
    			dp[x.b].second = x.t;
    			dp[x.b].first = x.val;
    			
    		}
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
