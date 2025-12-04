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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    ofstream out("K1.out");
    while (t--) {
    	int n, w;
        cin >> n >> w;
        double tot = 0;
        vector<array<int, 4>> vs(n);
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            vs[i] = {z, x, y, i};
        }
        sort(vs.begin(), vs.end());
        int idx = 0;
        vector<array<int, 4>> vec;
        int x = 0;
        int y = 0;
        vi ans;
        while (1) {
            while (idx < n && vs[idx][0] * 2 < w) {
                vec.push_back(vs[idx]);
                idx++;
            }
            if (vec.size() == 0) break;
            sort(vec.begin(), vec.end(), [&] (array<int, 4> f, array<int, 4> s) {
                ll d1 = 1ll * (f[1] - x) * (f[1] - x) + 1ll * (f[2] - y) * (f[2] - y);
                ll d2 = 1ll * (s[1] - x) * (s[1] - x) + 1ll * (s[2] - y) * (s[2] - y);
                return d1 > d2;
            });
            auto [vp, xp, yp, z] = vec.back();
            w += vp;

            tot += sqrt((1ll * (xp - x) * (xp - x) + 1ll * (yp - y) * (yp - y)));
            x = xp;
            y = xp;
            ans.push_back(z);
            vec.pop_back();
        }
        out << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            out << ans[i] << " ";
        }
        out << endl;
        cout << setprecision(10) << tot << endl;
    }

    return 0;
}
