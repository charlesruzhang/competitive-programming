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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }

    ll ans = 0;
    int idx = 0;
    stack<pair<ll, ll>> st;
    for (int i = 0; i < n; ++i) {
        ll mx = 0;
        ll z = a[i];
        while (!st.empty()) {
        	auto [x, y] = st.top();
            if (y == b[i]) {
                z += x - mx;
            } else if (x <= z) {
                mx = max(mx, x);
            } else {
                break;
            }
            st.pop();
        }

        st.push({z, b[i]});
        ans = max(ans, z);
        cout << ans << " ";
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
