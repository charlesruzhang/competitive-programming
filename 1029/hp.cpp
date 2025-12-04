// Problem: H. Incessant Rain
// Contest: Codeforces - Codeforces Round 1029 (Div. 3)
// URL: https://codeforces.com/contest/2117/problem/H
// Memory Limit: 192 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 300100;

int n, m, a[maxn];
pii qq[maxn];
bool vis[maxn];
vector<int> val[maxn], lsh[maxn], ls[maxn];

struct node {
	int pmx, smx, ans, sum;
	node(int a = 0, int b = 0, int c = 0, int d = 0) : pmx(a), smx(b), ans(c), sum(d) {}
};

inline node operator + (const node &a, const node &b) {
	node res;
	res.pmx = max(a.pmx, a.sum + b.pmx);
	res.smx = max(b.smx, b.sum + a.smx);
	res.ans = max({a.ans, b.ans, a.smx + b.pmx});
	res.sum = a.sum + b.sum;
	return res;
}

struct SGT {
	int N, n;
	vector<node> a;
	
	inline void init(int _n, vector<int> &val) {
		n = _n;
		N = 1;
		while (N < n + 2) {
			N <<= 1;
		}
		vector<node>(N * 2 + 5).swap(a);
		for (int i = 1; i <= n; ++i) {
			a[i + N].sum = val[i];
			a[i + N].pmx = a[i + N].smx = a[i + N].ans = max(val[i], 0);
		}
		for (int i = N; i; --i) {
			a[i] = a[i << 1] + a[i << 1 | 1];
		}
	}
	
	inline void update(int x, int y) {
		a[x += N].sum = y;
		a[x].pmx = a[x].smx = a[x].ans = max(y, 0);
		while (x >>= 1) {
			a[x] = a[x << 1] + a[x << 1 | 1];
		}
	}
} T[maxn];

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		vector<int>().swap(val[i]);
		vector<int>().swap(lsh[i]);
		vector<int>().swap(ls[i]);
		lsh[i].pb(0);
		lsh[i].pb(n);
	}
	for (int i = 1; i <= n; ++i) {
		lsh[a[i]].pb(i);
		ls[a[i]].pb(i);
		if (i > 1) {
			lsh[a[i]].pb(i - 1);
		}
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &qq[i].fst, &qq[i].scd);
		int x = qq[i].fst, y = qq[i].scd;
		lsh[y].pb(x);
		if (x > 1) {
			lsh[y].pb(x - 1);
		}
	}
	priority_queue<int> q1, q2;
	for (int i = 1; i <= n; ++i) {
		sort(lsh[i].begin(), lsh[i].end());
		lsh[i].erase(unique(lsh[i].begin(), lsh[i].end()), lsh[i].end());
		for (int j : ls[i]) {
			vis[j] = 1;
		}
		vector<int>((int)lsh[i].size()).swap(val[i]);
		for (int j = 1; j < (int)lsh[i].size(); ++j) {
			val[i][j] = vis[lsh[i][j]] ? 1 : -(lsh[i][j] - lsh[i][j - 1]);
		}
		for (int j : ls[i]) {
			vis[j] = 0;
		}
		T[i].init((int)lsh[i].size() - 1, val[i]);
		q1.push(T[i].a[1].ans);
	}
	for (int i = 1; i <= m; ++i) {
		int x = qq[i].fst, y = qq[i].scd;
		int p = lower_bound(lsh[a[x]].begin(), lsh[a[x]].end(), x) - lsh[a[x]].begin();
		q2.push(T[a[x]].a[1].ans);
		T[a[x]].update(p, -1);
		q1.push(T[a[x]].a[1].ans);
		a[x] = y;
		p = lower_bound(lsh[a[x]].begin(), lsh[a[x]].end(), x) - lsh[a[x]].begin();
		q2.push(T[a[x]].a[1].ans);
		T[a[x]].update(p, 1);
		q1.push(T[a[x]].a[1].ans);
		while (q1.size() && q2.size() && q1.top() == q2.top()) {
			q1.pop();
			q2.pop();
		}
		printf("%d%c", q1.top() >> 1, " \n"[i == m]);
	}
}

int main() {
	int T = 1;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}
