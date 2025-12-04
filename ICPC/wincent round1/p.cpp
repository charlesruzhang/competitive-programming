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
const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream out("P.out");
    mt19937_64 rng;
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    rng.seed(static_cast<unsigned long long>(seed));
    uniform_int_distribution<int> dist(0, 99);
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int k, p;
    	cin >> k >> p;
    	vi a(n);
    	vi val(n+1);

    	vi cnt(n);
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		cnt[a[i]]++;
    	}
    	vector<vector<double>> S(n-1, vector<double>(n));
    	S[n-2][n-2] = 1;
    	for (int i = 1; i < n; i++) {

    	}
    	for (int i = 0; i < n; i++) {
    		if (!cnt[i]) continue;

    	}
    }
    return 0;
}
