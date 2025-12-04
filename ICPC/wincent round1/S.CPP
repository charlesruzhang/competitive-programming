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
const int M = 10;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream out("S.out");
    vector<vector<char>> vc(M, vector<char>(M, '#'));
    for (int i = 0; i < M-1; i++) {
        for (int j = 0; j < M; j+=2) {
            vc[j][i] = '.';
        }
    }
    for (int j = 1; j < M; j+=2) {
        if (j % 4 == 1) {
            vc[j][0] = '.';
        } else {
            vc[j][M-2] = '.';
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            out << vc[i][j];
        }
        out << endl;
    }
    return 0;
}
