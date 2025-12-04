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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (k == 1) {
    	vi cnt(n+1);
    	for (int i = 0; i < n; i++) {
    		cnt[a[i]]++;
    	}
    	int mex = -1;
    	for (int i = 0; i <= n; i++) {
    		if (cnt[i] == 0) {
    			mex = i;
    			break;
    		}
    	}
    	ll summ = 0;
    	for (int i = 0; i < n; i++) {
    		if (mex > a[i] && cnt[a[i]] == 1) {
    			summ += a[i];
    		} else {
    			summ += mex;
    		}
    	}
    	cout << summ << endl;
    } else {
    	vi cnt(n +1);
    	for (int i = 0; i < n; i++) {
    		cnt[a[i]]++;
    	}
    	ll summ = 0;
    	for (int i = 0; i <= n; i++) {
    		if (cnt[i] == 1) {
    			summ += i;
    		} else if (cnt[i] == 0) {
    			if (i == n - 1) {
    				cout << summ + i << endl;
    				return;
    			}
    			ll ans = summ;
    			if (k % 2 == 0) {
    				ans += 1ll * (n - i) * (i + 1); 
    			} else {
    				ans += 1ll * (n - i) * i;
    			}
    			cout << ans << endl;
    			return;
    		} else {
    			ll ans = summ;
    			if (k % 2) {
    				ans += 1ll * (n - i) * (i + 1); 
    			} else {
    				ans += 1ll * (n - i) * i;
    			}
    			cout << ans << endl;
    			return;
    		}
    	}
    	cout << summ << endl;
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
