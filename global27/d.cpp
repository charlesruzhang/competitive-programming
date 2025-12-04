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
const ll MOD = 1e9+7;
const ll MAXX = 1e18;
const int INF = 1e9 + 7;
struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi powMod(mi base, long long exp) {
    mi result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b = a;
    vi c(n);
    for (int i = 0; i < n; i++) {
    	while (b[i] % 2 == 0) {
    		b[i] /= 2;
    		c[i]++;
    	}
    }
    stack<int> st;
    vector<mi> ans(n);
    for (int i = 0; i < n; i++) {
    	mi cur = a[i];
    	if (i) ans[i] = ans[i-1] + a[i];
    	else ans[i] = a[i];
    	int flag = 0;
    	while (st.size() && (b[st.top()] < cur.v || flag == 1)) {
    		ans[i] += (cur - b[st.top()]) * (powMod(2, c[st.top()]) - 1);
    		c[i] += c[st.top()];
    		cur *= powMod(2, c[st.top()]);
    		if (((ll)b[i] << c[i]) >= INF) {
    			flag = 1;
    		}
    		c[st.top()] = 0;
    		st.pop();
    	}
    	st.push(i);
    } 
    for (int i = 0; i < n; i++) {
    	cout << (int) ans[i] << " ";
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
