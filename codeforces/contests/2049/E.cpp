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
int query(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void find(int l, int r, int n) {
	int L = r - l + 1;
	int R = n - 1;
	while (L < R) {
		int M = (L + R + 1) / 2;
		int LL = l;
		int RR = LL + M - 1;
		if (RR >= n) {
			RR = n - 1;
			LL = RR - M + 1;
		}
		if (query(LL, RR)) {
			L = M;
		} else {
			R = M - 1;
		}
	}
	cout << "! " << L + 1 << endl;
}
void find2(int l, int r) {
	int L = 1;
	int R = r - l + 1;
	while (L < R) {
		int M = (L + R + 1) / 2;
		int LL = l;
		int RR = LL + M - 1;
		if (!query(LL, RR)) {
			L = M;
		} else {
			R = M - 1;
		}
	}
	cout << "! " << L + 1<< endl;
}
void solve() {
    int n;
    cin >> n;
    int l = 0;
    int r = n - 1;
	int mid = (l + r) / 2;
	int mmid = (l + mid) / 2;
	int rmid = (mid + 1 + r) / 2;
	int r1 = query(l, mmid);
	int r2 = query(mmid + 1, mid);
	int r3 = query(mid + 1, rmid);
	if (r1 == r2) {
		if (r3) {
			l = mid + 1;
			r = rmid;
		} else {
			l = rmid + 1;
			r = r;
		}
		if (r1 == 1) {
			find2(l, r);
		} else {
			find(l, r, n);
		}
	} else {
		if (r1 == 1) {
			l = l;
			r = mmid;
		} else {
			l = mmid + 1;
			r = mid;
		}
		if (!r3) {
			find(l, r, n);
		} else {
			find2(l, r);
		}
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
