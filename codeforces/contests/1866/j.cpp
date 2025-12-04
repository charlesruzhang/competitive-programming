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
    int N;
    cin >> N;
    int y = 0, n = 0;
    int yy = 0, nn = 0;
    int ynmax = 0, nymax = 0, ymax = 0, nmax = 0;
    for (int i = 0; i < N; i++) {
    	string s;
    	cin >> s;
    	if (s == "Yraglac") {
    		y++;
    		yy++;
    		nn = 0;
    	} else {
    		n++;
    		yy = 0;
    		nn++;
    	}
    	ynmax = max(ynmax, y - n);
    	nymax = max(nymax, n - y);
    	ymax = max(ymax, yy);
    	nmax = max(nmax, nn);
    }
    if (ynmax > nymax && ymax > nmax) {
    	cout << "Agree" << endl;
    } else if (ynmax == nymax && ymax == nmax) {
    	cout << "Agree" << endl;
    } else if (ynmax < nymax && ymax < nmax) {
    	cout << "Agree" << endl;
    } else {
    	cout << "Disagree" << endl; 
    }
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
