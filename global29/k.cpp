// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
ld query(int a, int b, int c, int d) {
	cout << "query " << a << " " << b << " " << c << " " << d << endl;
	ld res;
	cin >> res;
	return res;
}
int M = 100000;
void solve() {
    int l = 0;
    int r = M;
    while (l < r) {
    	int m1 = (2 * l + r + 1) / 3;
    	int m2 = (l + 2 * r + 2) / 3;
    	ld a1 = query(m1, 0, m1, M);
    	ld a2 = query(m2, 0, m2, M);
    	if (a1 <= a2) {
    		l = m1 + 1;
    	} else {
    		r = m2 - 1;
    	}
    }
    ld D = query(l, 0, l, M);
    int rad = (int) (D + 0.5) / 2;
    int L = 0;
    int R = M;
    while (L < R) {
    	int m = (L + R + 1) / 2;
    	ld a = query(l, 0, l, m);
    	if (a <= 1e-6) {
    		L = m;
    	} else {
    		R = m - 1;
    	}
    }
    int X = L + rad;
    //cout << X << endl;
    l = 0;
    r = M;
    while (l < r) {
    	int m1 = (2 * l + r + 1) / 3;
    	int m2 = (l + 2 * r + 2) / 3;
    	ld a1 = query(0, m1, M, m1);
    	ld a2 = query(0, m2, M, m2);
    	if (a1 <= a2) {
    		l = m1 + 1;
    	} else {
    		r = m2 - 1;
    	}
    }
    L = 0;
    R = M;
    while (L < R) {
    	int m = (L + R + 1) / 2;
    	ld a = query(0, l, m, l);
    	if (a <= 1e-6) {
    		L = m;
    	} else {
    		R = m - 1;
    	}
    }
    int Y = L + rad;
    cout << "answer " << Y << " " << X << " " << rad << endl;
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
