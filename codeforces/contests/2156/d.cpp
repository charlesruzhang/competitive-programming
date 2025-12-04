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
int query(int i, int x) {
	cout << "? " << i + 1 << " " << x << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    vi a(n-1);
    iota(a.begin(), a.end(), 0);
    vi ans(19);
    int round = 0;
    vi rem(n);
    iota(rem.begin(), rem.end(), 1);
    while (rem.size() >= 2) {
    	vi b;
    	vi c;
    	int tot = 0;
    	int need = 0;
    	for (int j = 0; j < rem.size(); j++) {
    		need += ((rem[j] & (1 << round)) > 0 ? 1: 0);
    	}
    	for (int y: a) {
    		int r = query(y, 1 << round);
    		tot += r;
    		if (!r) {
    			b.push_back(y);
    		} else {
    			c.push_back(y);
    		}
    	}
    	if (need != tot) {
    		ans[round] = 1;
    		swap(a, c);
    		vi R;
    		for (int v: rem) {
    			if ((v & (1 << round)) > 0) {
    				R.push_back(v);
    			}
    		}
    		swap(R, rem);
    	} else {
    		ans[round] = 0;
    		swap(a, b);
    		vi R;
    		for (int v: rem) {
    			if ((v & (1 << round)) == 0) {
    				R.push_back(v);
    			}
    		}
    		swap(R, rem);
    	}
    	round++;
    }

    cout << "! " << rem[0] << endl;
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
