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
    string s;
    string t;
    cin >> s >> t;
    int n = s.size();
    vi cnt(26);
    vi cnt2(26);
    int xa = 0, xb = 0;
    vector<char> d = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    for (int i = 0; i < n; i++) {
    	// int flag = 0;
    	// for (char c: d) {
    	// 	if (s[i] == c) {
    	// 		flag = 1;
    	// 		break;
    	// 	}
    	// }
    	if (s[i] == '@') {
    		xa++;
    		continue;
    	}
    	cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < n; i++) {
    	if (t[i] == '@') {
    		xb++;
    		continue;
    	}
    	cnt2[t[i] - 'a']++;
    }
    vi mark(26);
    for (char c : d) {
    	int z = c - 'a';
    	mark[z] = 1;
    }
    for (int i = 0; i < 26; i++) {
    	if (mark[i]) {
    		if (cnt[i] > cnt2[i]) {
    			xb-= cnt[i] - cnt2[i];
    		} else {
    			xa-= cnt2[i] - cnt[i];
    		}
    	} else {
    		if (cnt[i] != cnt2[i]) {
    			cout << "No" << endl;
    			return;
    		}
    	}
    }
    if (xa < 0 || xb < 0) {
    	cout << "No" << endl;
    } else {
    	cout << "Yes" << endl;
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
