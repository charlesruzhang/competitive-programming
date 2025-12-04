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
    int n, k , q;
    cin >> n >> k >> q;
    string s; 
    cin >> s;
    B = (int) sqrt(n);
    vector<Q> qrs(q);
    int idx = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        qrs[i] = Q(x, y, idx);
        idx++;
    }
    sort(qrs.begin(), qrs.end());
    vl ans(q);
    map<vector<int>, int> ma;
    vector<int> cur(26);
    ma[cur] = 0;
    vi p(n+1);
    for (int i = 0; i < n; i++) {
    	cur[s[i] - 'a'] = (cur[s[i] - 'a'] + 1) % k;
    	if (ma.find(cur) == ma.end()) {
    		ma[cur] = i + 1;
    		p[i+1] = i + 1;
    	} else {
    		p[i+1] = ma[cur];
    	}
    }
    int L = 0, R = -1;
    vi cnt(n+1);
    cnt[0] = 1;
    ll tot = 0;
    auto add = [&](int u) {
    	tot += cnt[p[u+1]];
    	cnt[p[u+1]]++;
    	//if (p[u] == 0) tot--;
    	//cout << L + 1 << " " << R + 1 << " " << tot << " " << u << endl;
    };
    auto remove = [&](int u) {
    	cnt[p[u+1]]--;
    	tot -= cnt[p[u+1]];
    	//if (p[u] == 0) tot++;
    	//cout << L + 1 << " " << R + 1 << " " << tot << " " << u  << endl;
    };
    for (auto& qr : qrs) {
        while (R < qr.y) {
        	R++;
        	add(R);
        }
        while (L > qr.x) {
        	L--;
        	add(L-1);
        }
        while (R > qr.y) {
        	R--;
        	remove(R+1);
        }
        while (L < qr.x) {
        	L++;
        	remove(L-2);
        }
        ans[qr.idx] = tot;
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
