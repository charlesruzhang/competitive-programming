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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> cnt(n+1);
    for (int i = 0; i < n; i++) {
    	int c;
    	cin >> c;
    	cnt[c].first++;
    }
    for (int i = 0; i <= n; i++) {
        cnt[i].second = i;
    }
    sort(cnt.begin(), cnt.end(), greater<>());
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i][0];
    }
    for (int i = 0; i < m; i++) {
    	cin >> a[i][1];
    }
    vvi ans(m);
    priority_queue<array<int, 3>> pq;
    vector<vector<set<int>>> vs(m);
    for (int i = 0; i < m; i++) {
        int j = 0;
        auto [sz, req] = a[i];
        int ct = (sz + req - 1) / req - 1;
        vs[i].resize(ct + 1);
        while (j < sz) {
            int pj = j;
            j = min(j + req, sz);
            pq.push({j - pj, i, ct});
            ct--;
        }
    }
    for (int i = 0; i < n; i++) {
        int z = cnt[i].second;
        vector<array<int, 3>> wait;
        for (int j = 0; j < cnt[i].first; j++) {
            if (!pq.size()) {
                cout << "-1" << endl;
                return;
            }
            auto [x, r, c] = pq.top();
            pq.pop();
            if (x > 1) wait.push_back({x - 1, r, c});
            vs[r][c].insert(z);
        }
        for (auto &[x, r, c] : wait) {
            pq.push({x, r, c});
        }
    }
    for (int i = 0; i < m; i++) {
        auto [sz, req] = a[i];
        ans[i].resize(sz);
        map<int, int> used;
        int base = 0;
        for (int j = 0; j < ((sz + req - 1) / req); j++) {
            map<int, int> nused;
            if (j) {
                auto it = vs[i][j].begin();
                while (it != vs[i][j].end()) {
                    int x = *it;
                    int mark = 0;
                    auto it2 = used.find(x);
                    if (it2 != used.end()) {
                        mark = 1;
                        ans[i][it2 -> second + req] = x;
                        nused[x] = it2 -> second + req;
                    }
                    ++it;
                    if (mark) vs[i][j].erase(prev(it));
                }
            }
            auto it = vs[i][j].begin();
            while (it != vs[i][j].end()) {
                while (ans[i][base]) {
                    base++;
                    //assert(base < j * req + req);
                }
                ans[i][base] = *it;
                nused[*it] = base;
                base++;
                ++it;
            }
            swap(used, nused);
        }
    }
    for (int i = 0; i < m; i++) {
    	for (int j = 0; j < ans[i].size(); j++) {
    		cout << ans[i][j] << " ";
    	}
    	cout << endl;
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
