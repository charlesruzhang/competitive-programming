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
    vi x(n), y(n);
    map<int, vector<pii>> ma;
    set<int> s;
    vi v;
    for (int i = 0; i < n; i++) {
    	cin >> x[i];

    	cin >> y[i];

    	ma[x[i]+y[i]].push_back({x[i], y[i]});
    	v.push_back(x[i]+y[i]);
    }
    int ans = -1;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
    	if (ma[v[i]].size() % 2) {
    		ans = v[i];
    		break;
    	}
    }
    vector<pii> vec = ma[ans];
    for (int i = 0; i < v.size(); i++) {
    	if (v[i] == ans) continue;
    	auto it = ma.find(v[i]);
    	int l = 0;
    	int r = (*it).second.size() - 1;
		while (l < r) {
			vec.push_back({(*it).second[l].first, ans - (*it).second[l].first});
			vec.push_back({(*it).second[r].first, ans - (*it).second[r].first});
			l++;
			r--;
		}
    }
    sort(vec.begin(), vec.end());
    int c = 0;
    int xx = 0;
    for (int i = 0, j = 0; i < vec.size(); i=j) {
    	if (i != vec.size() - 1 && vec[i] == vec[i+1]) {
    		j = i + 2;
    	} else {
    		j = i + 1;
    		cout << vec[i].first << " " << vec[i].second << endl;
    		break;
    		//break;
    	}
    }
    //assert(xx == 1);
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
