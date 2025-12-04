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
int query(int type, int x, int y = 0) {
	if (type == 1) {
		cout << "+ " << x << endl;
	} else {
		cout << "? " << x << " " << y << endl;
	}
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    if (n == 2) {
    	cout << "! 2 1 1 2" << endl;
    	int res;
    	cin >> res;
    	return;
    }
    int ret = query(1, n);
    ret = query(1, n - 1);
    int miss = n;
    for (int i = 1; i + 1 <= n; i+=2) {
    	int res = query(2, i, i + 1);
    	if (res == -1) {
    		if (i + 1 != n) {
    			int res2 = query(2, i, n);
    			if (res2 == -1) {
    				miss = i;
    			} else {
    				miss = i + 1;
    			}
    			break;
    		} else {
    			int res2 = query(2, 1, i);
    			if (res2 == -1) {
    				miss = i;
    			} else {
    				miss = i + 1;
    			}
    			break;
    		}
    	}
    }
    // if (n == 3) {
    // 	vi A(4);
    // 	vi B(4);
    // 	A[miss] = B[miss] = 3;
    // 	int cur = 1;
    // 	for (int i = 1; i <= 3; i++) {
    // 		if (A[i] == 0) {
    // 			A[i] = cur;
    // 			cur++;
    // 		}
    // 	}
    // 	cur = 1;
    // 	for (int i = 3; i >= 1; i--) {
    // 		if (B[i] == 0) {
    // 			B[i] = cur;
    // 			cur++;
    // 		}
    // 	}
    // 	cout << "! ";
    // 	for (int i = 1; i <= 3; i++) {
    // 		cout << A[i] << " ";
    // 	}
    // 	for (int i = 1; i <= 3; i++) {
    // 		cout << B[i] << " ";
    // 	}
    // 	cout << endl;
    // 	int rett;
    // 	cin >> rett;
    // 	return;
    	
    // }
    ret = query(1, 2 * n - 1);
    int cur = n - 1;
    vi seq(n + 1);
    int b = 1;
    int timer = 1;
    while (1) {
    	seq[timer++] = cur;
    	if (b) {
    		cur = n - cur;
    	} else {
    		cur = n - 1 - cur;
    	}
    	b ^= 1;
    	if (timer > n) {
    		break;
    	}
    }
    vi ans(n + 1);
    ans[miss] = n;
    int C = 0;
    set<int> S;
    for (int i = 1; i <= n; i++) {
    	if (i == n) continue;
    	S.insert(i);
    }
    for (int i = 1; i <= n; i++) {
    	if (i == miss) {
    		continue;
    	}
    	int res = query(2, i, miss);
    	ans[i] = seq[res];
    	S.erase(seq[res]);
    	C++;
    	if (C == n - 2) break;
    }
    assert(S.size() == 1);
    for (int i = 1; i <= n; i++) {
    	if (ans[i] == 0) {
    		ans[i] = *(S.begin());
    		break;
    	}
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
    	cout << ans[i] << " ";
    }
    for (int i = 1; i <= n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
    int rett;
    cin >> rett;
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
