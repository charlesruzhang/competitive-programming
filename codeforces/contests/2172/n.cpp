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
    int n, k, b;
    cin >> n >> k >> b;
    if (k % 2) {
    	cout << "No" << endl;
    	return;
    }
    if (n == 1) {
    	cout << "Yes" << endl;
    	cout << 0 << endl;
    	return;
    }
    vector<pii> A;
    if (b == n - 1) {
    	if (k == 0) {
    		cout << "No" << endl;
    		return;
    	}
    	for (int i = 1; i <= k - 1; i++) {
    		A.push_back({i, k});
    	}
    	for (int i = k; i < n; i++) {
    		A.push_back({i, i + 1});
    	}
    } else {
    	if (b == n - 2) {
    		cout << "No" << endl;
    		return;
    	}
    	if (k == 0 && b) {
    		cout << "No" << endl;
    		return;
    	} else if (k == 0) {
    		if (n == 2) {
    			cout << "No" << endl;
    			return;
    		}
    		for (int i = 1; i <= n - 1; i++) {
    			A.push_back({i, i + 1});
    		}
    		A.push_back({n, 1});
    	} else {
    		if (k >= b) {
    			for (int i = b + 1; i <= n - 1; i++) {
    				A.push_back({i, i + 1});
    			}
    			A.push_back({n, b + 1});
    			if (b == n - 3) {
    				int K = (b + 1) / 2 * 2;
    				if (k > K) {
    					assert(k == K + 2);
    					if (n <= 4) {
    						cout << "No" << endl;
    						return;
    					}
    					A.push_back({1, b + 2});
    					A.push_back({2, b + 3});
    					for (int i = 3; i <= b; i++) {
    						A.push_back({i, b + 1});
    					}
    				} else {
    					assert(k == K);
    					for (int i = 1; i <= b; i++) {
    						A.push_back({i, b + 1});
    					}
    				}
    			} else {
    				int K = (b % 2) ? b + 1 : b;
    				for (int i = 1; i <= b; i++) {
						A.push_back({i, b + 1});
					}
					if (k > K) {
						A.push_back({b + 2, n});
						K += 2;
					}
					int l = b + 3;
					for (int i = K; i < k; i++) {
						if (l == n) {
							assert(i + 1 == k);
							break;
						}
						A.push_back({l, b + 1});
						l++;
					}
    			}
    		} else {
    			// k < b;
    			for (int i = b + 1; i <= n - 1; i++) {
    				A.push_back({i, i + 1});
    			}
    			A.push_back({n, b + 1});
    			for (int i = 1; i <= k; i++) {
    				A.push_back({i, b + 1});
    			}
    			int prev = 1;
    			for (int i = k + 1; i <= b; i++) {
    				A.push_back({i, prev});
    				prev = i;
    			}
    		}
    	}
    	
    }
    cout << "Yes" << endl;
    cout << A.size() << endl;
    for (auto [x, y] : A) {
    	cout << x << " " << y << endl;
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
