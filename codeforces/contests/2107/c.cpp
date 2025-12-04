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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll minn = 0;
    vector<ll> pref(n+1);
    ll maxz = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pref[i+1] = pref[i] + a[i];
            minn = min(minn, pref[i+1]);
            maxz = max(maxz, pref[i+1] - minn);
        } else {
            minn = 0;
            if (maxz > k) {
                cout << "NO" << endl;
                return;
            }
            maxz = 0;
        }
    }
    if (maxz > k) {
        cout << "NO" << endl;
        return;
    }
    int i = n - 1;
    vector<ll> suf(n);
    while (i >= 0) {
        int j = i;
        ll cur = 0;
        ll maxx = 0;
        while (s[j] != '0') {
            cur += a[j];
            maxx = max(maxx, cur);
            j--;
            if (j < 0) break;
        }
        suf[i] = maxx;
        i = j - 1;      
    }
    i = 0;
    vector<ll> pre(n);
    while (i < n) {
        int j = i;
        ll cur = 0;
        ll maxx = 0;
        while (s[j] != '0') {
            cur += a[j];
            maxx = max(maxx, cur);
            j++;
            if (j >= n) break;
        }
        pre[i] = maxx;
        i = j + 1;      
    }
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans[i] = a[i];
        } else {
            ans[i] = -1e16;
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            flag = 1;
            ll suff = (i == 0) ? 0 : suf[i - 1];
            ll prex = (i == n-1) ? 0 : pre[i + 1];
            ans[i] = k - prex - suff;
            break;
        }
    }
    if (!flag && maxz != k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
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
