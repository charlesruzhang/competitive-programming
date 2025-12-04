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
    int n;
    cin >> n;
    vi a(n);
    vvi v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    vvi best(n + 1);
    vi minn(n + 1, INF);
    minn[1] = 0;
    for (int i = 1; i <= n - 1; i++) {
        best[i + 1].resize(v[i + 1].size() + 1);
        vector<pii> W;
        int p = v[i].size();
        int q = v[i+1].size();
        for (int j = 0; j < v[i].size(); j++) {
            W.push_back({v[i][j], i});
        }
        for (int j = 0; j < v[i+1].size(); j++) {
            W.push_back({v[i+1][j], i + 1});
        }
        sort(W.begin(), W.end(), greater<>());
        int cnt = 0;
        int cur = 0;
        for (auto [u, v] : W) {
            if (v == i + 1) {
                best[i+1][cur] = cur + min(p + minn[i-1], p - cnt + minn[i]);
                minn[i+1] = min(minn[i+1], best[i+1][cur]);
                cur++;
            } else {
                cnt++;
            }
        }
        best[i+1][q] = q + minn[i];
        minn[i + 1] = min(minn[i+1], best[i+1][q]);
        //cout << i + 1 << " " << minn[i + 1] << endl;
    }
    cout << minn[n] << endl;
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
