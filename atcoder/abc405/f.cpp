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
int B;
struct Q
{
    int x, y, idx;
    bool operator<(const Q & other) const {
        if (x / B != other.x / B) 
            return x < other.x; 
        return ((x / B) & 1) ? (y > other.y) : (y < other.y); 
    }
};
void solve() {
    int n, m , q;
    cin >> n >> m;
    B = (int) sqrt(4 * m + 2);
    vi vec(4 * m + 2, -1);
    vector<pii> vv;
    set<int> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vv.push_back({y, x});
        s.insert(x);
        s.insert(y);
    }
    vector<int> ma(2 * n + 1);
    auto it = s.begin();
    int id = 0;
    while (it != s.end()) {
    	ma[*it] = (++id) * 2;
    	++it;
    }
    for (auto [x, y] : vv) {
    	vec[ma[x]] = ma[y];
    	vec[ma[y]] = ma[x];
    }
    for (int i = 0; i < 2 * n + 1; i++) {
    	//cout << i << " " << ma[i] << endl;
    }
    cin >> q;
    vector<Q> qrs(q);
    int idx = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        auto it2 = s.lower_bound(x);
        x = (it2 == s.end()) ? 4 * m + 1 : ma[*it2] - 1;
        it2 = s.lower_bound(y);
        y = (it2 == s.end()) ? 4 * m + 1 : ma[*it2] - 1;
        qrs[i] = Q(x, y, idx);
        idx++;
        //cout << x << " " << y << " " << idx << endl;
    }
    sort(qrs.begin(), qrs.end());
    vl ans(q);
    int L = 1, R = -1;
    ll cur = 0;
    auto addl = [&]() {
    	if (vec[L + 1] == -1) return;
    	if (vec[L + 1] > L && vec[L + 1] < R) {
    		cur --;
    	} else {
    		cur ++;
    	}
    };
	auto addr = [&]() {
    	if (vec[R - 1] == -1) return;
    	if (vec[R - 1] > L && vec[R - 1] < R) {
    		cur --;
    	} else {
    		cur ++;
    	}
    };
    auto removel = [&]() {
		if (vec[L - 1] == -1) return;
    	if (vec[L - 1] > L && vec[L - 1] < R) {
    		cur ++;
    	} else {
    		cur --;
    	}
    };
    auto remover = [&]() {
		if (vec[R + 1] == -1) return;
    	if (vec[R + 1] > L && vec[R + 1] < R) {
    		cur ++;
    	} else {
    		cur --;
    	}
    };
    for (auto& qr : qrs) {
        while (R < qr.y) {
        	R += 2;
        	addr();
        }
        while (L > qr.x) {
        	L -= 2;
        	addl();
        }
        while (R > qr.y) {
        	R -= 2;
        	remover();
        }
        while (L < qr.x) {
        	L += 2;
        	removel();
        }
        ans[qr.idx] = cur;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
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
