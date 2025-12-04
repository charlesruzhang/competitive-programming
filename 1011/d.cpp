#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
const int MAXN = 2e5;
void solve() {
    int n, k;
    cin >> n >> k;
    vi d(n);
    for (int i = 0; i < n; i++) {
    	cin >> d[i];
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = n-1-k; i >= 0; i--) {
    	pq.push(d[i]);
    	if ((n - i) < pq.size() * (k + 1)) {
    		pq.pop();
    	}
    }
    ll summ = 0;
    while (!pq.empty()) {
    	int x = pq.top();
    	pq.pop();
    	summ += x;
    }
    cout << summ << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
