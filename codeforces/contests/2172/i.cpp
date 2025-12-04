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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int Ans = 0;
    vector<char> S(n);
    for (int i = 0; i < n; i++) {
    	S[i] = s[i];
    }
    auto f = [&] (vector<char>& S, int m) {
    	if (m < 0) return;
	    vvi a(k);
	    int ans = 0;
	    for (int i = 1; i < n; i++) {
	    	if (S[i] == S[i-1]) {
	    		a[i % k].push_back(0);
	    	} else {
	    		a[i % k].push_back(1);
	    		ans ++;
	    	}
	    }
	    vi D(m + 1);
	    for (int i = 0; i < k; i++) {
	    	vi E = D;
	    	int sz = a[i].size();
	    	vi V;
	    	for (int j = 0; j < sz; j++) {
	    		if (a[i][j] == 0) V.push_back(j);

	    	}
	    	vi W;
	    	int T = m;
	    	T = min(T, n / k + 1);
	    	vi dp1(T+1);
	    	vi dp2(T+1);
	    	for (int j = 1; j < V.size(); j++) {
	    		W.push_back(V[j] - V[j-1]);
	    	}
	    	for (int j = 0; j < W.size(); j++) {
	    		for (int l = T; l >= W[j]; l--) {
	    			dp1[l] = max(dp1[l], dp1[l - W[j]] + 2);
	    		}
	    		swap(dp1, dp2);
	    	}
	    	for (int j = 0; j <= T; j++) {
	    		dp1[j] = max(dp1[j], dp2[j]);
	    	}

	    	for (int l = 0; l <= m; l++) {
	    		for (int j = 0; j <= min(l, T); j++) {
	    			E[l] = max(dp1[j] + D[l - j], E[l]);
	    		}
	    	}
	    	swap(D, E);
	    }
	    Ans = max(Ans, D[m] + 1 + ans);
	};

	f(S, m);
	for (int i = 0; i < k; i++) {
		S[i] = (S[i] == 'B' ? 'R' : 'B');
	}
	f(S, m - 1);
	for (int i = 0; i < k; i++) {
		S[n - i - 1] = (S[n - 1 - i] == 'B' ? 'R' : 'B');
	}
	f(S, m - 2);
	for (int i = 0; i < k; i++) {
		S[i] = (S[i] == 'B' ? 'R' : 'B');
	}
	f(S, m - 1);
	cout << Ans << endl;
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
