#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
const ll MOD = 998244353;
const ld EPS = 1e-9;

vector<int> argsort(const vector<int>& arr) {
    vector<int> indices(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return arr[i] > arr[j];
    });

    return indices;
}

ll solve() {
    ll n;
    cin >> n;
    vi w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        a[s-1].push_back(t-1);
        a[t-1].push_back(s-1);
    }
    vi done(n, -1);
    queue<int> q;
    q.push(1);
    int c = 1;
    done[0] = 0;
    vi parent(n, 0);
    parent[0] = -1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vi v;
        for (int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            if (done[y] == -1) {
                v.push_back(y);
                done[y] = c;
                parent[y] = x;
            }
        }
        for (int i =0; i < v.size(); i++) {
            q.push(v[i]);
        }
        c++;
    }
    vi idx = argsort(w);
    int init = 0;
    vi removed(n, 0);
    while (init<n) {
        int target = idx[init];
        if (init != 0 && removed[target] == 0) {
            cout << target + 1 << endl;
            return 0;
        }
        int cur = target;
        while (parent[cur] != -1) {
            removed[cur] = 1;
            cur = parent[cur];
        }
    }
    cout << 0 << endl;
    return 0;
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
