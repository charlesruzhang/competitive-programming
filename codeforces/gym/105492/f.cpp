#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int maxn = 111111;

int n, m, dfn[maxn], low[maxn], ts, gc, deg[maxn], g[maxn];
bool in[maxn];
stack<int> s;
ld p[maxn], gp[maxn];
vector<vector<int>> e(maxn);

void tarjan(int u) {
    dfn[u] = low[u] = ++ts;
    in[u] = 1;
    s.push(u);

    for (int v : e[u]) {
        if (! dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
        else if (in[v]) low[u] = min(low[u], dfn[v]);
    } 

    if (dfn[u] == low[u]) {
        gp[++gc] = 1;

        while (1) {
            int tmp = s.top();
            s.pop();
            in[tmp] = 0;
            g[tmp] = gc;

            gp[gc] *= 1 - p[tmp];

            if (tmp == u) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) scanf("%Lf", &p[i]);

    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);

        e[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) if (! dfn[i]) tarjan(i);

    for (int i = 1; i <= n; i++) {
        for (int v : e[i])
            if (g[v] != g[i]) deg[g[i]]++;
    }

    ld ans = 0;

    for (int i = 1; i <= gc; i++) {
        if (! deg[i]) ans = max(ans, gp[i]);
    }

    // printf("%.250Lf\n", ans);
    cout << setprecision(200) << ans << endl;
}