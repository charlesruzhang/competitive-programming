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

    cout << "mul 999999999" << endl;
    int x;
    cin >> x;

    cout << "digit" << endl;
    cin >> x;

    if (n != 81) {
        cout << "add " << n - 81 << endl;
        cin >> x;
    }
    cout << "!" << endl;
    cin >> x;
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
