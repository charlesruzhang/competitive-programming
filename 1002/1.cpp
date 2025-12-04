#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
int solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int,int> ma;
    map<int,int> mb;
    int ca = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma[a[i]] ++;
        if (ma[a[i]] == 2) {
            ca++;
        }
    }
    int cb = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];

        mb[b[i]] ++;
        if (mb[b[i]] == 2) {
            cb++;
        }
    }
    if (ca * cb >= 3) {
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
