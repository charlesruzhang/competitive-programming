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
    string s;
    cin >> s;
    vector<pii> cnt(26);
    for (int i = 0; i < n; i++) {
    	int z = s[i] - 'a';
    	cnt[z].first++;
    }
    for (int i = 0; i < 26; i++) {
    	cnt[i].second = i;
    }
    sort(cnt.begin(), cnt.end());
    vector<char> ans(n);
    for (int i = 0; i < n; i+=2) {
    	ans[i] = (char) (cnt.back().second + 'a');
    	cnt.back().first --;
    	if (cnt.back().first == 0) cnt.pop_back();
    }

    for (int i = 1; i < n; i+=2) {
    	ans[i] = (char) (cnt.back().second + 'a');
    	cnt.back().first --;
    	if (cnt.back().first == 0) cnt.pop_back();
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i];
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
