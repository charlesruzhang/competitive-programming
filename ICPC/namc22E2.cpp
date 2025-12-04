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
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n + 1; i++) {
    	for (int j = 0; j < 3; j++) {
    		int x;
    		cin >> x;
    		if (x) v[i].push_back(x);
    	}
    }
    vector<pii> ans;
    auto mover = [&] (int f, int s) {
        int x = v[f].back();
        v[f].pop_back();
        v[s].push_back(x);
        ans.push_back({f, s});
    };
    for (int i = 0; i < n; i++) {
    	while (v[i].size() != 3) {
    		mover(n, i);
    	}
    }
    int T = n;
    int X = n - 1;
    while (T) {
    	int z = v[X].back();
        mover(X, T);
    	int flag = 0;
    	for (int i = 0; i < X; i++) {
    		for (int j = 0; j < 3; j++) {
    			if (v[i][j] == z) {
    				for (int k = 2; k > j; k--) {
    					mover(i, T);
    				}
    				mover(i, X);
    				for (int k = 2; k > j; k--) {
    					mover(T, i);
    				}
    				mover(X, T);
    				mover(X, i);
    				flag = 1;
    				break;
    			}
    		}
    		if (flag) break;
    	}
    	if (!flag) {
    		assert(v[X][0] == z || v[X][1] == z);
    		if (v[X][1] == z) {
    			mover(X, T);
    		} else {
    			assert(false);
    		}
    	}

        flag = 0;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] == z) {
                    for (int k = 2; k > j; k--) {
                        mover(i, X);
                    }
                    mover(i, T);
                    for (int k = 3; k > j; k--) {
                        mover(X, i);
                    }
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) {
            assert(v[X][0] == z);
            mover(X, T);
        }
        T--; X--;
    }
    // cout << "???" << endl;
    // for (int i = 1; i <= n; i++) {
    //     assert(v[i].size() == 3);
    //     for (int j = 0; j < 3; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    assert(ans.size() <= 20 * n);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        auto [f, s] = ans[i];
        cout << f + 1 << " " << s + 1 << endl;
    }
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
