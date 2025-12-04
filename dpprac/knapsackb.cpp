#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int, int>;
const ll MAXX = 1e18;
const int MOD = 998244353;
void solve() {
    int n, m1, m2, m3;
    cin >> n >> m1 >> m2 >> m3;
    vi c1(m1), v1(m1);
    vi c2(m2), v2(m2);
    vi c3(m3), v3(m3);
    for (int i = 0; i < m1; i++) {
        cin >> c1[i] >> v1[i];
    }
    for (int i = 0; i < m2; i++) {
        cin >> c2[i] >> v2[i];
    }
    for (int i = 0; i < m3; i++) {
        cin >> c3[i] >> v3[i];
    }
    int N = 2000;
    vi dp1(N), dp2(N), dp3(N);
    for (int i = 0; i < m1; i++) {
        for (int j = N; j >= c1[i]; j--) {
            dp1[j] = max(dp1[j], dp1[j-c1[i]] + v1[i]);
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = N; j >= c2[i]; j--) {
            dp2[j] = max(dp2[j], dp2[j-c2[i]] + v2[i]);
        }
    }
    for (int i = 0; i < m3; i++) {
        for (int j = N; j >= c3[i]; j--) {
            dp3[j] = max(dp3[j], dp3[j-c3[i]] + v3[i]);
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            ans = max(ans, 1ll * dp1[i] * dp2[j] * dp3[n - i - j]);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}