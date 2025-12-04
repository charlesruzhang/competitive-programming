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
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0;
    for (int i = 1; i < n; i++) {
    	if (s[i] != s[i-1]) {
    		flag = 1;
    		break;
    	}
    }
    if (!flag) {
    	cout << -1 << endl;
    	return;
    }
    vector<pair<int, char>> vec(3);
    vec[0] = pii(0, 'I');
    vec[1] = pii(0, 'L');
    vec[2] = pii(0, 'T');
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
    	v[i] = s[i];
    	if (s[i] == 'I') {
    		vec[0].first++;
    	} else if (s[i] == 'L') {
    		vec[1].first++;
    	} else {
    		vec[2].first++;
    	}
    }
    vi ans;
    function <void(void)> add = [&]() {
    	sort(vec.begin(), vec.end());
    	vector<char> vp(v.size()+1);
    	int idx = -1;
    	int tar = -1;
    	for (int i = 0; i < v.size() - 1; i++) {
    		if (v[i] != vec[0].second && v[i+1] != vec[0].second && v[i] != v[i+1]) {
    			idx = i;
    			tar = 0;
    			break;
    		}
    	}
    	if (idx == -1) {
    		for (int i = 0; i < v.size() - 1; i++) {
	    		if (v[i] != vec[1].second && v[i+1] != vec[1].second && v[i] != v[i+1]) {
	    			idx = i;
	    			tar = 1;
	    			break;
	    		}
    		}
    	}
    	vp[idx+1] = vec[tar].second;
    	vec[tar].first++;
    	ans.push_back(idx+1);
    	for (int i = 0; i < v.size(); i++) {
    		if (i <= idx) {
    			vp[i] = v[i];
    		} else {
    			vp[i+1] = v[i];
    		}
    	}
    	swap(vp, v);
    };
    while (vec[0].first != vec[1].first || vec[1].first != vec[2].first) {
    	add();
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << endl;
    }
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
