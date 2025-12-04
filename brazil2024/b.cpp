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
const int maxn = 111;

int n, m, q, dist[maxn][maxn], mid[maxn][maxn], act[maxn][maxn];
vector<int> a[1111111];

void print_path(int u, int v, bool print_last=1) {
    // printf("%d %d %d %d\n", u, v, dist[u][v], mid[u][v]);
    // assert (u && v);
    if (u == v) {
        if (print_last) printf("%d ", u);
        return;
    }
    if (dist[u][v] == 1) {
        printf("%d %d ", u, act[u][v]);

        if (print_last) printf("%d ", v);
        return;
    }

    print_path(u, mid[u][v], print_last=0);
    print_path(mid[u][v], v);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1, cnt, k; i <= n; i++) {
        scanf("%d", &cnt);

        for (int j = 0; j < cnt; j++) {
            scanf("%d", &k);
            a[k].pb(i);
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dist[i][j] = i == j? 0: 1e6;

    for (int i = 1; i <= m; i++) {
        for (int j : a[i])
            for (int k : a[i])
                dist[j][k] = j == k? 0: 1, act[j][k] = i;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] + dist[k][j] == dist[i][j] && k != i && k != j)
                    mid[i][j] = k;

    scanf("%d", &q);

    while (q--) {
        int u, v, ans = INT_MAX;
        pii pts;
        scanf("%d%d", &u, &v);

        for (int i : a[u])
            for (int j : a[v])
                if (dist[i][j] + 2 < ans)
                    ans = dist[i][j] + 2, pts = {i, j};

        if (ans > 1e4) {
            puts("-1");
            continue;
        }

        printf("%d\n", ans);
        printf("%d ", u);
        print_path(pts.first, pts.second);
        printf("%d\n", v);
    }
}