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
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vi ga(n+1), gb(n+1);
    for (int i = n - 1; i >= 0; i--) {
    	ga[i] = gcd(ga[i+1], a[i]);
    	gb[i] = gcd(gb[i+1], b[i]); 
    }
    vector<array<int, 3>> vec;
    int ca = 0, cb = 0;
    int maxx = 1;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < vec.size(); j++) {
    		auto [x, y, c] = vec[j];
    		x = gcd(x, b[i]);
    		y = gcd(y, a[i]);
    		vec[j] = {x, y, c};
    	}
    	vec.push_back({gcd(ca, b[i]), gcd(cb, a[i]), 1});
    	ca = gcd(ca, a[i]);
    	cb = gcd(cb, b[i]);

    	sort(vec.begin(), vec.end());
    	vector<array<int, 3>> nvec;
    	for (int j = 1; j < vec.size(); j++) {
    		if (vec[j-1][0] != vec[j][0] || vec[j-1][1] != vec[j][1]) {
    			nvec.push_back(vec[j-1]);
    		} else {
    			vec[j][2] += vec[j-1][2];
    		}
    	}
    	nvec.push_back(vec[vec.size()-1]);
    	swap(vec, nvec);

    	for (int j = 0; j < vec.size(); j++) {
    		auto [x, y, c] = vec[j];
    		//cout << i << " " << x << " " << y << " " << c << endl;
    		int z = gcd(x, ga[i+1]) + gcd(y, gb[i+1]);
    		if (z > maxx) {
    			maxx = z;
    			cnt = c;
    		} else if (z == maxx) {
    			cnt += c;
    		}
    	}
    }
    cout << maxx << " " << cnt << endl;
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
