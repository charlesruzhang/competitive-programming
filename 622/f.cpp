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
void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int> ma;
    int cur = n;
    for (int i = 2; i * i <= n; i++) {
    	int cnt = 0;
    	while (cur % i == 0) {
    		cur /= i;
    		cnt ++;
    	}
    	if (cnt) ma[i] = cnt;
    }
    if (cur > 1) {
    	ma[cur] = 1; 
    }
    auto it = ma.begin();
    int tot = 1;
    while (it != ma.end()) {
    	auto [x, y] = *it;
    	tot *= y + 1;
    	++it;
    }
    int ctot = tot;
    map<int, int> A = ma;
    while (q--) {
    	int k;
    	cin >> k;
    	if (k == 2) {
    		ctot = tot;
    		A = ma;
    	} else {
    		int x;
    		cin >> x;
    		int cx = x;
    		for (int i = 2; i * i <= x; i++) {
    			int cnt = 0;
    			while (cx % i == 0) {
    				cnt++;
    				cx /= i;
    			}
    			if (cnt) {
    				int prev = A[i];
    				A[i] = prev + cnt;
    				ctot /= (prev + 1);
    				ctot *= (prev + cnt + 1);
    			}
    		}
    		if (cx > 1) {
    			int prev = A[cx];
    			A[cx] = prev + 1;
				ctot /= (prev + 1);
				ctot *= (prev + 2);
    		}
    		int cctot = ctot;
    		int flag = 0;
    		for (int i = 2; i * i <= ctot; i++) {
    			int cnt = 0;
    			while (cctot % i == 0) {
    				cnt ++;
    				cctot /= i;
    			}
    			if (cnt > 0 && A[i] < cnt) {
    				cout << "NO" << endl;
    				flag = 1;
    				break;
    			}
    		}
    		if (!flag && cctot > 1 && A[cctot] < 1) {
    			cout << "NO" << endl;
    			flag = 1;
    		}
    		if (!flag) {
    			cout << "YES" << endl;
    		}
    	}
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
