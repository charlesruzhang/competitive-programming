#include <bits/stdc++.h>
using namespace std;

// Simple DSU for 26 uppercase letters
struct DSU {
    vector<int> p;
    DSU(int n=0): p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) p[b] = a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> names(N);
    DSU dsu(26);
    vector<bool> letterUsed(26,false);

    // Read names, mark letters used, and union their two letters
    for(int i = 0; i < N; i++){
        cin >> names[i];
        int u = names[i][0] - 'A';
        int v = names[i][1] - 'A';
        letterUsed[u] = letterUsed[v] = true;
        dsu.unite(u, v);
    }

    // Group edges (names) by DSU root of their first letter
    vector<vector<int>> compEdges(26);
    for(int i = 0; i < N; i++){
        int root = dsu.find(names[i][0] - 'A');
        compEdges[root].push_back(i);
    }

    int answer = 0;

    // We'll use a standard DFS (Kuhn) for maximum bipartite matching
    vector<int> matchR;
    vector<char> usedLocal;
    function<bool(int,const vector<vector<int>> &)> dfs = [&](int u, const vector<vector<int>> &adj){
        for(int v: adj[u]){
            if (!usedLocal[v]) {
                usedLocal[v] = 1;
                if (matchR[v] < 0 || dfs(matchR[v], adj)) {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    };

    // Process each non-empty component
    for(int root = 0; root < 26; root++){
        auto &edges = compEdges[root];
        int m = edges.size();
        if (m == 0) continue;

        // Build bipartite adjacency: left nodes [0..m), right nodes [0..m)
        // connect i->j iff names[i].back() == names[j].front()
        vector<vector<int>> adj(m);
        for(int i = 0; i < m; i++){
            char endC = names[edges[i]][1];
            for(int j = 0; j < m; j++){
                if (names[edges[j]][0] == endC)
                    adj[i].push_back(j);
            }
        }

        // Run Kuhn's DFS-based matching
        matchR.assign(m, -1);
        int matchCount = 0;
        for(int u = 0; u < m; u++){
            usedLocal.assign(m, 0);
            if (dfs(u, adj)) matchCount++;
        }

        // Each matched pair merges two edges into one trail,
        // so we need (m - matchCount) trails, but at least 1.
        answer += max(1, m - matchCount);
    }

    cout << answer << "\n";
    return 0;
}
