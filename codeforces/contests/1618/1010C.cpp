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
	int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		a[i][j] = s[j] - '0';
    	}
    }
    vi r(n), c(m);
    vvi rs(4);
    vvi cs(4);
    for (int i = 0; i < n; i++) {
    	int tot = 0;
    	for (int j = 0; j < m; j++) {
    		tot ^= a[i][j];
    	}
    	if (r[i] = tot) rs[r[i]].push_back(i);
    }

    for (int j = 0; j < m; j++) {
    	int tot = 0;
    	for (int i = 0; i < n; i++) {
    		tot ^= a[i][j];
    	}
    	if (c[j] = tot) cs[c[j]].push_back(j);
    }
    int cnt = 0;
    for (int i = 1; i <= 3; i++) {
    	while (rs[i].size() && cs[i].size()) {
    		int R = rs[i].back();
    		int C = cs[i].back();
			cnt++;
			a[R][C] = i ^ a[R][C];
    		rs[i].pop_back();
    		cs[i].pop_back();
    	}
    }
    int x = 0, y = 0;
    int minn = 1e9;
    for (int i = 1; i <= 3; i++) {
    	if (rs[i].size()) {
    		minn = min((int) rs[i].size(), minn);
    	} else {
    		minn = min((int) cs[i].size(), minn);
    	}
    }
    for (int i = 0; i < minn; i++) {
    	vi R, C;
    	for (int j = 1; j <= 3; j++) {
    		if (rs[j].size()) {
    			R.push_back(rs[j].back());
    			rs[j].pop_back();
    		} else {
    			C.push_back(cs[j].back());
    			cs[j].pop_back();
    		}
    	}
    	if (R.size() >= 2) {
    		int y = (C.size()) ? C[0] : 0;
    		for (int j = 0; j < R.size(); j++) {
    			cnt++;
    			int z = r[R[j]];
    			a[R[j]][y] = z ^ a[R[j]][y];
    		}
    	} else {
    		int y = (R.size()) ? R[0] : 0;
    		for (int j = 0; j < C.size(); j++) {
    			cnt++;
    			int z = c[C[j]];
    			a[y][C[j]] = z ^ a[y][C[j]];
    		}
    	}
    }
    vi RS, CS;
    for (int j = 1; j <= 3; j++) {
    	if (rs[j].size()) {
    		if (RS.size() == 0) swap(rs[j], RS);
    		else {
    			for (int i = 0; i < rs[j].size(); i++) {
    				RS.push_back(rs[j][i]);
    			}
    		}
    	}
    	if (cs[j].size()) {
    		if (CS.size() == 0) swap(cs[j], CS);
    		else {
    			for (int i = 0; i < cs[j].size(); i++) {
    				CS.push_back(cs[j][i]);
    			}
    		}
    	}
    }
    int maxx = max(RS.size(), CS.size());
    for (int i = 0; i < maxx / 2; i++) {
    	int R1 = 0, R2 = 0, C1 = 0, C2 = 0;
    	if (RS.size()) {
    	 	R1 = RS.back();
    		RS.pop_back();
    	}
    	if (RS.size()) {
    	 	R2 = RS.back();
    		RS.pop_back();
    	}
    	if (CS.size()) {
    	 	C1 = CS.back();
    		CS.pop_back();
    	}
    	if (CS.size()) {
    	 	C2 = CS.back();
    		CS.pop_back();
    	}
    	cnt += 3;
    	if (R1 == R2 || C1 == C2) {
    		cnt--;
    	}
    	a[R1][C2] = r[R1] ^ a[R1][C2];
    	a[R2][C1] = c[C1] ^ a[R2][C1];
    	a[R2][C2] = r[R1] ^ c[C1] ^ a[R2][C2];
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		cout << a[i][j];
    	}
    	cout << '\n';
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
