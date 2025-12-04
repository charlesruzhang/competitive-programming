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
//istream in("r2a1.in");
void solve(ofstream& out) {
    ll a, b, m;
    cin >> a >> b >> m;
    ll count = 0;
    for (int i = 1; i <= 9; i++) {
    	for (int j = i; j <= 9; j++) {
    		ll now = 0;
    		for (int k = i; k <= j; k++) {
    			now = 10 * now + k;
    		}
    		for (int k = j - 1; k >= i; k--) {
    			now = 10 * now + k;
    		}
    		if (a <= now && now <= b && now % m == 0) {
    			count++;
    		}
    	}
    }
    out << count << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    ofstream out("r2a1.txt");
    for (int i = 0; i < t; i++) {
        out << "Case #" << i + 1 << ": ";
        solve(out);
    }
    return 0;
}
