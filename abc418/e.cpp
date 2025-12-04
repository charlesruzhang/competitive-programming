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
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        // Hash the first element
        size_t hash1 = hash<T1>{}(p.first);
        // Hash the second element
        size_t hash2 = hash<T2>{}(p.second);
        // Combine the two hash values
        return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
    }
};
void solve() {
    unordered_map<pair<int,int>, int, hash_pair> ma;
    int n;
    cin >> n;
    vector<vector<int>> points(n, vi(2));
    for (int i = 0; i < n; i++) {
    	cin >> points[i][0] >> points[i][1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int xd = points[j][0] - x;
            int yd = points[j][1] - y;
            if (xd < 0) {
                xd = -xd;
                yd = -yd;
            } else if (xd == 0 && yd < 0) {
                yd = -yd;
            }
            int g = gcd(xd, yd);
            xd /= g;
            yd /= g;
            ans += ma[{xd, yd}];
            ma[{xd, yd}]++;
        }
    }
    unordered_map<pair<int,int>, int, hash_pair> mp;
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        for (int j = i + 1; j < n; j++) {
            int xd = points[j][0];
            int yd = points[j][1];
            int xs = x + xd;
            int ys = y + yd;
            ans -= mp[{xs, ys}];
            mp[{xs, ys}]++; 
        }
    }
    cout << ans << endl;
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
