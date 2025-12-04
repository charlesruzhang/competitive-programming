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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n-1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    stack<int> st;
    int g = 0;
    vi left(n), right(n);
    for (int i = 0; i < n; i++) {
    	while (!st.empty() && st.top() >= a[i]) {
    		st.pop();
    	}
   		if (!st.empty()) {
   			int x = st.top();
   			right[i] = x;
   			g = gcd(g, abs(a[i] - x));
   		}
    	st.push(a[i]);
    }
    stack<int> st2;
    for (int i = n - 1; i >= 0; i --) {
    	while (!st2.empty() && st2.top() >= a[i]) {
    		st2.pop();
    	}
    	if (!st2.empty()) {
    		int x = st2.top();
    		left[i] = x;
    		g = gcd(g, abs(a[i] - x));
    	}
    	st2.push(a[i]);
    }
    if (g == 0) {
    	cout << k << " " << 1ll * k * (k + 1) / 2 << endl;
    	return;
    }
    vector<int> v;
    for (int i = 1; i * i <= g; i++) {
    	if (g % i == 0) {
    		v.push_back(i);
    		if (i * i != g) v.push_back(g / i);
    	}
    }
    sort(v.begin(), v.end());
    ll tot = 0;
    int cnt = 0;
    int z = *min_element(a.begin(), a.end());
    for (int i = 0; i < v.size(); i++) {
    	if (v[i] > z && v[i] - z <= k) {
    		int d = v[i] - z;
    		int f = 0;
    		for (int j = 0; j < n; j++) {
    			if (right[j] != 0 && ((a[j] + d) % (right[j] + d) != 0) && ((right[j] + d) % (a[j] + d) != 0)) {
    				f = -1;
    				break;
    			}
    			if (left[j] != 0 && ((a[j] + d) % (left[j] + d) != 0) && ((left[j] + d) % (a[j] + d) != 0)) {
    				f = -1;
    				break;
    			}
    		}
    		if (f == -1) continue;
    		tot += d; 
    		cnt ++;
    	}
    }
    cout << cnt << " " << tot << endl;
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
