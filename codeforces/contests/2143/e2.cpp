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
void solve(string st) {
	int n = st.size();
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
    	s[i] = st[i];
    }
    if (n % 2 == 1) {
    	return;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	cnt += (s[i] == '(');
    }
    int half = n / 2;
    if (cnt % 2 != half % 2) {
    	return;
    }
    cout << "Q = " << st << endl;
    if (s[n - 1] == '(') {
    	for (int i = n - 1; i >= 0; i--) {
	    	if (i && s[i] == s[i-1] && s[i] == '(') {
	    		s[i-1] = s[i] = ')';
	    	}
	    }
	    if (s[n-1] == '(') {
		    for (int i = n - 1; i >= 0; i--) {
		    	if (i && s[i] == s[i-1] && s[i] == ')') {
		    		swap(s[n-1], s[i-1]);
		    		break;
		    	}
		    }
	    }
    }
    for (int i = 0; i < n - 2; i++) {
    	if (i && s[i] == s[i-1] && s[i] == ')') {
    		s[i] = '(';
    		s[i-1] = '(';
    	}
    }
    if (s[n-1] == '(') {
    	cout << -2 << endl;
    	return;
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
    	if (s[i] == '(') {
    		cnt++;
    	}
    	if (s[i] == ')') {
    		int c = cnt / 2 * 2;
    		swap(s[i], s[i+c]);
    		cnt = c;
    	}
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
    	cnt += (s[i] == '(') ? 1 : -1;
    	if (cnt < 0) {
    		cout << -3 << endl;
    		return;
    	}
    }
    for (int i = n - 2; i >= 0; i--) {
    	if (cnt == 0) break;
    	if (s[i] == s[i+1] && s[i] == '(') {
    		s[i] = s[i+1] = ')';
    		cnt -= 4;
    	}
    }
	if (cnt > 0) {
		cout << -1 << endl;
		return;
	}    
	cnt = 0;
    for (int i = 0; i < n; i++) {
    	cnt += (s[i] == '(') ? 1 : -1;
    	if (cnt < 0) {
    		assert(false);
    	}
    	cout << s[i];
    }
    if (cnt != 0) {
    	assert(false);
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 8;
    ll t = 1 << T;
    while (t--) {
    	string s;
    	for (int i = 0; i < T; i++) {
    		if ((1 << i) & t) {
    			s+='(';
    		} else {
    			s+=')';
    		}
    	}
        solve(s);
    }
    return 0;
}
