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
    ofstream out("W.out");
    instream in
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	string s;
        cin >> s;
        vi cnt(26);
        for (int i = 0; i < n; i++) {
            int z = s[i] - 'a';
            cnt[z]++;
        }
        int l = 1;
        int r = n;
        while (l < r) {
            int m = (l + r + 1) / 2;
            int flag = 1;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] % m != 0 && (cnt[i] + 1) % m != 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                l = m;
            } else {
                r = m - 1; 
            }
        }
    }
    return 0;
}
