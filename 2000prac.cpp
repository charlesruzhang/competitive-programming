#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
const int MOD = 1e9+7;
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b = a;
    sort(b.begin(), b.end());
    auto bx = unique(b.begin(), b.end());
    b.erase(bx, b.end());
    map<int, int> ma;
    for (int i = 0; i < b.size(); i++) {
        ma[b[i]] = i + 1;
    }
    vi seen(b.size(), -1);
    vi vec(b.size(), 0);
    vi last(n, -1);
    int maxx = 0;
    int maxans = -1;
    for (int i = 0; i < n; i++) {
        int z = ma[a[i]];
        seen[z - 1] = i;
        vec[z-1] = max(vec[z-1], 1);
        if (z >= 2 && seen[z - 2] != -1 && b[z-2] + 1 == b[z-1]) {
            last[i] = seen[z - 2];
            vec[z-1] = vec[z-2] + 1;
        }
        if (maxx < vec[z-1]) {
            maxx = vec[z-1];
            maxans = i;
        }
    }
    cout << maxx << endl;
    int cur = maxans;
    vi v;
    while (cur != -1) {
        v.push_back(cur);
        cur = last[cur];
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << " ";
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}