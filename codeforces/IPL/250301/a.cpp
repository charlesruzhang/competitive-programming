#include <bits/stdc++.h>
using namespace std;

int n, dep[66], cnt;
long long ans[66];
vector<vector<int>> e(66);
vector<int> primes;
const int N = 400;
vector<int> p(N, 1);
void pre() {
	for (int i = 2; i * i <= N; i++) {
		if (p[i]) {
			for (int j = 2; i * j <= N; j++) {
				p[i*j] = 0;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		if (p[i]) {
			primes.push_back(i);
		}
	}
}

int dfs1(int u, int f) {
    dep[u] = 1;

    for (int v : e[u]) {
        if (v != f) dep[u] = max(dep[u], dfs1(v, u) + 1);
    }

    if (~f)
        e[u].erase(find(e[u].begin(), e[u].end(), f));

    sort(e[u].begin(), e[u].end(), [&](int i, int j) {
        return dep[i] > dep[j];
    });

    return dep[u];
}

void dfs2(int u, int f, int cur) {
    if (u == 1) {
        ans[u] = 1;
    } else {
        ans[u] = ans[f] * primes[cur];
    }

    for (int i = 0; i < e[u].size(); i++) {
        if (! i) {
            dfs2(e[u][i], u, cur);
        } else dfs2(e[u][i], u, ++cnt);
    }
}

int main() {
    scanf("%d", &n);

    pre();
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs1(1, -1);
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
    puts("");
}