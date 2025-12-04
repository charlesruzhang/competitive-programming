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
const ll MAXX = 1e16;
void solve() {
    int n, m;
    cin >> n >> m;
    if (m > n) swap(n, m);
    if (n >= 17 && m >= 17) {
        vector<vector<int>> answ(30, vi(30));
        answ[17][17] = 814905630;
        answ[18][17] = 514814169;
        answ[19][17] = 313744178;
        answ[20][17] = 204855408;
        answ[21][17] = 477981516;
        answ[22][17] = 90014676;
        answ[23][17] = 83481166;         
        answ[24][17] = 942145627;
        answ[25][17] = 516277901;
        answ[26][17] = 448281132;
        answ[27][17] = 410569693;
        answ[28][17] = 42060917;
        answ[29][17] = 965027986;
        answ[18][17] = 514814169;
        answ[18][18] = 300222286;
        answ[19][18] = 407603921;
        answ[20][18] = 633973116;
        answ[21][18] = 192767215;
        answ[22][18] = 326980585;
        answ[23][18] = 420939052;
        answ[24][18] = 107998150;
        answ[25][18] = 594761476;
        answ[26][18] = 6302453;
        answ[27][18] = 895854896;
        answ[19][17] = 313744178;
        answ[19][18] = 407603921;
        answ[19][19] = 199940456;
        answ[20][19] = 336646927;
        answ[21][19] = 194959030;
        answ[22][19] = 178595155;
        answ[23][19] = 912902034;
        answ[24][19] = 165780380;
        answ[25][19] = 202882160;
        answ[26][19] = 284515286;
        answ[20][17] = 204855408;
        answ[20][18] = 633973116;
        answ[20][19] = 336646927;
        answ[20][20] = 313825924;
        answ[21][20] = 889307762;
        answ[22][20] = 245396285;
        answ[23][20] = 982189947;
        answ[24][20] = 800954162;
        answ[25][20] = 742107905;
        answ[21][17] = 477981516;
        answ[21][18] = 192767215;
        answ[21][19] = 194959030;
        answ[21][20] = 889307762;
        answ[21][21] = 247461800;
        answ[22][21] = 839713465;
        answ[23][21] = 490577110;
        answ[22][17] = 90014676; 
        answ[22][18] = 326980585;
        answ[22][19] = 178595155;
        answ[22][20] = 245396285;
        answ[22][21] = 839713465;
        answ[22][22] = 357361881;
        cout << answ[m][n] << endl;
        return;
    }
    vector<int> legal;
    for (int i = 0; i < (1 << m); i++) {
        if ((i & (i << 1)) == 0) {
            legal.push_back(i);
        }
    }
    int sz = legal.size();
    vector<vector<int>> vec(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if ((legal[i] & legal[j]) == 0) {
                vec[i].push_back(j);
            }
        }
    }
    vi dp(sz, 1);
    for (int i = 1; i < n; i++) {
        vi ndp(sz);
        for (int j = 0; j < sz; j++) {
            for (int k : vec[j]) {
                ndp[j] = (ndp[j] + dp[k]) % MOD;
            }
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for (int x: dp) {
        ans = (ans + x) % MOD;
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
