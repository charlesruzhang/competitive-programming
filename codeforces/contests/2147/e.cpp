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
void solve(int t) {
    int n, q;
    cin >> n >> q;
    vl a(n);
    vi cnt(35);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	for (int j = 0; j <= 30; j++) {
    		if ((1 << j) & a[i]) {
    			cnt[j]++;
    		}
    	}
    }

    vector<pii> qrs(q);
    for (int i = 0; i < q; i++) {
    	int x;
    	cin >> x;
    	qrs[i] = {x, i};
    }
    sort(qrs.begin(), qrs.end());
    int j = 0;
    ll tot = 0;
    vl ans(q);
    int minn = 0;
    while (1) {
        int flag = 0;
    	for (int i = 0; i < n; i++) {
            if (a[i] & (1ll << minn)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            minn++;
            continue;
    	}
        vi cnt(33);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 32; j++) {
                if ((1ll << j) & a[i]) {
                    cnt[j] = 1;
                }
            }
        }
        int A = 0;
        for (int i = 0; i <= 32; i++) {
            A += cnt[i];
        }
        for (int z = minn; z >= 0; z--) {
            int mask = (1ll << (z + 1)) - 1;
            ll M = MAXX;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (M > (1ll << z) - (a[i] & mask)) {
                    M = (1ll << z) - (a[i] & mask);
                    idx = i;
                }
            }   
            a[idx] += max(0ll, M);
            tot += max(0ll, M);
            //cout << z << "  ? " << tot << endl;
        }
        //cout << minn << " " << tot << " " << A << endl;
        while (j < q && qrs[j].first < tot) {
    		ans[qrs[j].second] = A;
    		j++;
    	}
        if (j == q) break;
        minn++;
    }
    for (int i = 0; i < q; i++) {
    	//cout << i + 1 << " " << ans[i] << endl;
    	cout << ans[i] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i);
    }
    return 0;
}
