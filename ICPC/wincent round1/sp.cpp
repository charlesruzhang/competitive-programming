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
const int M = 150;
int G = 1024;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream out("S.out");
    int M1 = 64;
    int M2 = 32;
    int M3 = 32;
    int M4 = 32;
    int cnt = 0;
    vector<vector<char>> vc(M, vector<char>(M, '#'));
    for (int i = 0; i <= M1; i++) {
        for (int j = 0; j <= M1; j++) {
            if (gcd(G, i) != gcd(G, j)) {
                vc[i][j] = '.';
                cnt++;
            }
        }
    }
    vc[0][0] = '.';
    for (int i = 0; i <= M2; i++) {
        for (int j = M1 + 2; j <= M1 + M2 + 2; j++) {
            if (gcd(G, i) != gcd(G, j - M1 - 2)) {
                vc[i][j] = '.';
                cnt++;
            }
        }
    }
    vc[0][M1+1] = '.';
    vc[0][M1 + 2] = '.';
    for (int i = 0; i <= M3; i++) {
        for (int j = M1 + M2 + 4; j <= M1 + M2 + M3 + 4; j++) {
            if (gcd(G, i) != gcd(G, j - M1 - M2 - 4)) {
                vc[i][j] = '.';
                cnt++;
            }
        }
    }

    vc[0][M1+M2+3] = '.';
    vc[0][M1+M2+4] = '.';
    cnt+=5;
    while (cnt > 5000) {
        for (int i = M-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                if (i && j && (i + 1 < M) && (j + 1) < M) {
                    if (vc[i][j] == '.') {
                        int c = 0;
                        if (vc[i+1][j] == '.') {
                            c++;
                        }

                        if (vc[i-1][j] == '.') {
                            c++;
                        }
                        if (vc[i][j+1] == '.') {
                            c++;
                        }
                        if (vc[i][j-1] == '.') {
                            c++;
                        }
                        if (c == 1 && cnt > 5000) {
                            vc[i][j] = '#';
                            cnt--;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    out << M << " " << M << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            out << vc[i][j];
        }
        out << endl;
    }
    cout << cnt << endl;
    return 0;
}
