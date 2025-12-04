#include <bits/stdc++.h>
using namespace std;
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
struct AC {
  int N, P;
  const int A = 26;
  vector <vector <int>> next;
  vector <int> link, out_link; // out_link[v] = nearest ancestor of v where an input pattern ended which is also a suffix link of v.
  vector <vector <int>> out;
  AC(): N(0), P(0) {node();}
  int node() {
    next.emplace_back(A, 0);
    link.emplace_back(0);
    out_link.emplace_back(0);
    out.emplace_back(0);
    return N++;
  }
  inline int get (char c) {
    return c - 'a';
  }
  int add_pattern (const string T) {
    int u = 0;
    for (auto c : T) {
      if (!next[u][get(c)]) next[u][get(c)] = node();
      u = next[u][get(c)];
    }
    out[u].push_back(P);
    return P++;
  }
  void compute() {
    queue <int> q;
    for (q.push(0); !q.empty();) {
      int u = q.front(); q.pop();
      for (int c = 0; c < A; ++c) {
        int v = next[u][c];
        if (!v) next[u][c] = next[link[u]][c];
        else {
          link[v] = u ? next[link[u]][c] : 0;
          out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
          q.push(v);
        }
      }
    }
  }
  int advance (int u, char c) {
    while (u && !next[u][get(c)]) u = link[u];
    u = next[u][get(c)];
    return u;
  }
};

//usage: AC aho;
//vector<int> len(m);
//for (auto s: v) {
//    len[aho.add_pattern(s)] = s.size();
//}
//aho.compute();
//for (int i = 0; i < n; i++) {
//    char c = s[i];
//    u = aho.advance(u, c);
//    if (!start[i]) continue;
//    for (int v = u; v; v = aho.out_link[v]) {
//        for (auto p : aho.out[v]) {
//            int xx = (i - len[p] >= 0 ? dp[i - len[p]] : 0) + 1;
//            if (dp[i] > xx) {
//                dp[i] = xx;
//                ans[i] = p;
//                prev[i] = i - len[p];
//            }
//        }
//   }
//}

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

void solve() {
    int n, l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    vector<string> t;
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n; j++) {
        	if (i == j) continue;
            if (s[j].find(s[i]) != string::npos) {
            	flag = 1;
            	break;
            }
        }
        if (!flag) t.push_back(s[i]);
    }

    n = t.size();

    AC aho;
    for (int i = 0; i < n; i++) {
    	aho.add_pattern(t[i]);
    }
    aho.compute();
    int N = aho.N;
    int m = (1 << n);

    vector<mi> dp(N * m);
    dp[0] = 1;
    for (int i = 0; i < l; i++) {
        vector<mi> ndp(N * m);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < m; k++) {
                for (int c = 0; c < 26; c++) {
                    int next = aho.next[j][c];
                    int z = k;
                    for (int x : aho.out[next]) {
                    	z |= (1 << x);
                    }
                    ndp[next * m + z] += dp[j * m + k];
                }
            }
        }
        swap(dp, ndp);
    }

    mi ans = 0;
    for (int i = 0; i < N; i++) {
    	ans += dp[(i + 1) * m - 1];
    }
    cout << (int) ans << endl;
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