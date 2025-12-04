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
    int k, n;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b = a;
    reverse(b.begin(), b.end());
    if (b == a) {
    	cout << "YES" << endl;
    	return;
    }
    if (k == 1) {
    	cout << "YES" << endl;
    	return;
    }
    sort(b.begin(), b.end());
    int z = b[k-2];
    vi c;
    vector<pii> e;
    for (int i = 0; i < n; i++) {
    	if (a[i] < z) {
    		c.push_back(a[i]);
    		e.push_back({a[i], i});
    	}
    }
    vi d = c;
    reverse(d.begin(), d.end());
    if (d != c) {
    	cout << "NO" << endl;
    	return;
    }
    cout << "?" << endl;
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + ((a[i] == z) ? 1 : 0);
    }
    int target = k - 1 - d.size();
    if (target % 2 == 1) {
    	if (d.size() % 2 == 1) {
    		cout << "NO" << endl;
    		return;
    	}
    	int idx = d.size() / 2;
    	int l = e[idx-1].second;
    	int r = e[idx].second;
    	if (pref[r] - pref[l] == 0) {
    		cout << "No" << endl;
    		return;
    	}
    	target--;
    }
    int left = (e.size() - 1) / 2;
    int right = e.size() / 2;
    cout << "?" << endl;
    int tot = 0;
    for (int i = 0; i < (d.size() + 1) / 2; i++) {
    	//cout << i << endl;
    	int l = (left - i - 1 >= 0) ? e[left - i - 1].second : 0;
    	int lr = e[left - i].second;
    	int rl = e[right + i].second;
    	int r = (right + i + 1 < e.size()) ? e[right + i + 1].second : n-1;
    	//cout << l << " " <<lr << " " << rl << " " << r << endl;
    	tot += 2 * min(pref[lr + 1] - pref[l], pref[r + 1] - pref[rl]);
    }
    if (tot >= target) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
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
