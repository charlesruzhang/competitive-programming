#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define um unordered_map
#define us unordered_set
#define pb push_back
#define mp make_pair
#define yorn(f) puts(f? "yes" : "no")
#define newl printf("\n")

template<typename... Arg>
void print(string format, Arg... args) {
    #ifdef DEBUG 
    printf(format.c_str(), args...);
    #endif
}

const int mod = 998244353;
const int maxn = 555555;

int w, h, K, dp[2][maxn], pre[55][444444];
char ac[10][55];

void print_vec(vi v) {
    for (int k : v) printf("%d ", k);
    puts("");
}

vi mask2vec(int k) {
    vi res;

    for (int i = 0; i < h; i++)
        res.pb(k % 5), k /= 5;

    // assert (! k);

    return res;
}

int vec2mask(vi& v) {
    assert(v.size() == h);
    int mask = 0, pow = 1;

    for (int i = 0; i < v.size(); i++) {
        mask += pow * v[i];
        pow *= 5;
    }

    return mask;
}

map<int, vi> tran;

int main() {
    memset(dp, 0x0f, sizeof(dp));

    scanf("%d%d%d", &w, &h, &K);

    for (int i = 0; i < 1 << h; i++) {
        vi vec;
        int cnt = 0;
        bool f = 1;

        for (int j = 0; j < h; j++) {
            if (i & (1 << j)) vec.pb(4), cnt++;
            else {
                int cnt = (i >> j - 1 & 1) + (i >> j + 1 & 1);
                if (cnt > K) f = 0;
                vec.pb(K - cnt);
            }
        }

        if (f) dp[1][vec2mask(vec)] = cnt;
    }

    for (int i = 0; i < pow(5, h); i++) {
        vi fi = mask2vec(i);

        bool f = 1;

        for (int k : fi) if (k != 4 && k > K) f = 0;

        if (! f) continue;

        for (int j = 0; j < 1 << h; j++) {
            bool f = 1;
            for (int k = 0; k < h; k++)
                if (fi[k] != 4 && (j >> k & 1) + (j >> k - 1 & 1) + (j >> k + 1 & 1) != fi[k]) 
                    f = 0;
            
            if (! f) continue;

            vi se;

            for (int k = 0; k < h; k++) {
                if (j & (1 << k)) se.pb(4);
                else {
                    int cnt = (j >> k - 1 & 1) + (j >> k + 1 & 1) + (fi[k] == 4) + (k > 0 && fi[k - 1] == 4) + (k < h - 1 && fi[k + 1] == 4);

                    if (cnt > K) f = 0;
                    se.pb(K - cnt);
                }
            }

            if (f) {
                if (tran.find(vec2mask(se)) == tran.end()) tran[vec2mask(se)] = vi();
                tran[vec2mask(se)].pb(i);
            }
        }
    }

    for (int i = 2; i <= w; i++) {
        for (int j = 0; j < pow(5, h); j++) dp[i & 1][j] = 1e9;
        for (auto [m, vm] : tran) {
            vi vec = mask2vec(m);
            int sum = 0;
            for (int k = 0; k < h; k++) sum += vec[k] == 4;
            for (int m2 : vm) {
                if (dp[(i & 1) ^ 1][m2] + sum < dp[i & 1][m]) {
                    dp[i & 1][m] = dp[(i & 1) ^ 1][m2] + sum;
                    pre[i][m] = m2;
                }
            }
        }
    }

    int ans = INT_MAX, last = 0;

    for (int i = 0; i < pow(5, h); i++) {
        vi vec = mask2vec(i);
        bool f = dp[w & 1][i] <= w * h;

        for (int j = 0; j < h; j++)
            if (vec[j] != 0 && vec[j] != 4) f = 0;

        if (f && dp[w & 1][i] < ans) {
            ans = dp[w & 1][i];
            last = i;
        }
    }

    for (int i = w; i; i--) {
        vi vec = mask2vec(last);

        for (int j = 0; j < h; j++)
            ac[j][i - 1] = vec[j] == 4? '#': '*';
        
        last = pre[i][last];
    }

    printf("%d\n", ans);

    for (int i = 0; i < h; i++) printf("%s\n", ac[i]);
}