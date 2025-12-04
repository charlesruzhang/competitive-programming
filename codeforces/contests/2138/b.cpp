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
	int n, q;
	cin >> n >> q;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    vi f(n, -1);
    vector<int> l(n+1, 0);
    stack<pii> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first < a[i]) {
            st.pop(); 
        }
        l[i] = st.empty() ? -1 : st.top().second;
        st.push({a[i], i});
    }
    vector<int> r(n+1, n+1);
    stack<pii> st2;
    for (int i = n - 1; i >= 0; i--) {
        while (!st2.empty() && st2.top().first > a[i]) {
            st2.pop(); 
        }
        r[i] = st2.empty() ? n : st2.top().second;
        st2.push({a[i], i});
    }
    vector<int> best(n, 2 * n);
    for (int i = 1; i < n; i++) {
        if (l[i] == -1) continue;
        best[l[i]] = min(best[l[i]], r[i]);
    }
    vector<int> suff(n+3, 2 * n);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = min(suff[i+1], best[i]);
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (suff[u] <= v && v - u >= 2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
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
