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
    string no = "Keine Loesung";
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2) {
    	cout << no << endl;
    	return;
    }
    int flag = 1;
    int l = 0;
    for (int i = 0; i < n; i+=2) {
    	if (s[i] != s[i+1]) {
    		flag = 0;
    		break;
    	}
    	if (s[i] == '<') {
    		l++;
    	} else {
    		l--;
    	}
    }
    if (!flag || l) {
    	cout << no << endl;
    	return;
    }
    vector<char> ans;
    for (int i = 0; i < n; i += 2) {
    	if (l > 0 && s[i] == '<') {
    		ans.push_back('[');
    	} else if (l < 0 && s[i] == '<') {
    		ans.push_back(']');
    	} else if (l > 0 && s[i] == '>') {
    		ans.push_back(']');
    	} else {
    		ans.push_back('[');
    	}
    	l += (s[i] == '<' ? 1 : -1);
    }
    for (char c : ans) {
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
