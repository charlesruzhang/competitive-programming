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
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    ll target = d;
    ll low = 0;
    ll high = 8;
    ll dem = 3;
    int start = 2;
    vector<char> ans;
    for (int x = 0; x < n; x++) {
    	ll cur = 0;
    	for (int i = start; i < start + dem; i++) {
    		cur *= 2;
    		if (i < s.size()) cur += (s[i] - '0');
    	}
    	if (cur >= target) {
    		low = target;
    		high = high;
    		low <<= 3;
    		high <<= 3;
    		target = low + (high - low) * d / 8;
    		ans.push_back('B');
    	} else {
    		low = low;
    		high = target;
    		low <<= 3;
    		high <<= 3;
    		target = low + (high - low) * d / 8;
    		ans.push_back('A');
    	}
    	dem += 3;
    }
    for (char c: ans) {
    	cout << c;
    }
    cout << endl;
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
