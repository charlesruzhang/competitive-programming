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
vi query(vi& a) {
	cout << "? " << a.size() << " ";
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
	int ct;
	cin >> ct;
	vi ans(ct);
	for (int i = 0; i < ct; i++) {
		cin >> ans[i];
	}
	return ans;
}
void solve() {
    int n;
    cin >> n;
    vi done(n * n + 1, 0);
    vi a(n * n + 1);
    set<int> s;
    for (int i = 0; i <= n * n; i++) {
    	a[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
    	vi ans = query(a);
    	if (ans.size() >= n + 1) {
    		cout << "! ";
    		for (int j = 0; j <= n; j++) {
    			cout << ans[i] << " ";
    		}
    		cout << endl;
    		return;
    	} else {
    		for (int x : ans) {
    			done[x-1] = n - i;
    		}
    		vi b;
    		for (int j = 0; j <= n * n; j++) {
    			if (done[j] == 0) {
    				b.push_back(j + 1);
    			}
    		}
    		swap(a, b);
    	}
    }
    int target = 0;
    vi ans;
    for (int i = n * n; i >= 0; i--) {
    	if (done[i] == target) {
    		target++;
    		ans.push_back(i + 1);
    	}
    }
    reverse(ans.begin(), ans.end());
    assert(ans.size() == n + 1);
    cout << "! ";
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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
