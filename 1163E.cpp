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
struct HopcroftKarp {
    int nL, nR;
    vector<vector<int>> g;        // g[u] -> list of right vertices
    vector<int> dist, pairU, pairV;
    HopcroftKarp(int nL, int nR): nL(nL), nR(nR), g(nL), dist(nL), pairU(nL,-1), pairV(nR,-1) {}
    void add_edge(int u, int v){ g[u].push_back(v); }

    bool bfs(){
        queue<int> q;
        fill(dist.begin(), dist.end(), -1);
        for(int u=0; u<nL; ++u) if(pairU[u]==-1){ dist[u]=0; q.push(u); }
        bool found=false;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int v: g[u]){
                int u2 = pairV[v];
                if(u2==-1) found=true;
                else if(dist[u2]==-1){ dist[u2]=dist[u]+1; q.push(u2); }
            }
        }
        return found;
    }
    bool dfs(int u){
        for(int v: g[u]){
            int u2 = pairV[v];
            if(u2==-1 || (dist[u2]==dist[u]+1 && dfs(u2))){
                pairU[u]=v; pairV[v]=u; return true;
            }
        }
        dist[u]=-1; return false;
    }
    int max_matching(){
        int m=0;
        while(bfs()){
            for(int u=0; u<nL; ++u)
                if(pairU[u]==-1 && dfs(u)) ++m;
        }
        return m;
    }
    vector<pair<int,int>> pairs() const {
        vector<pair<int,int>> res;
        for(int u=0; u<nL; ++u) if(pairU[u]!=-1) res.push_back({u, pairU[u]});
        sort(res.begin(), res.end());
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 21; i >= 0; i--) {
    	HopcroftKarp G(i + 1, n);
    	for (int z = 0; z < n; z++) {
    		if (a[z] >= (1 << (i + 1))) continue;
    		for (int j = i; j >= 0; j--) {
    			if (((1 << j) & a[z])) {
    				G.add_edge(j, z);
    			}
    		}
    	}
    	int z = G.max_matching();
    	if (z == i + 1) {
    		auto P = G.pairs();
    		vi vec(i+1);
    		for (auto [u, v]: P) {
    			vec[u] = a[v];
    			cout << u << " " << (a[v] & (1<<u)) << "!!" << endl;
    		} 
    		cout << i + 1 << endl;
    		int cur = 0;
    		for (int j = 0; j < (2 << i); j++) {
    			cout << cur << " ";
    			int x = j + 1;
    			cur ^= vec[__builtin_ctz(x & (-x))];
    		}
    		cout << endl;
    		return;
    	}
    }
    cout << 0 << endl;
    cout << 0 << endl;
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
