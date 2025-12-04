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
    int n, m;
    cin >> n >> m;
    vvi c(n, vi(m));
    auto maxc = [&] (int i, int j) {
        return max(max(max(c[i][j], c[i-1][j]), c[i-1][j-1]), c[i][j-1]);
    };
    auto check = [&] (int i, int j) {
        int cc = maxc(i, j);
        return (cc == c[i-1][j] || !c[i-1][j]) 
        &&     (cc == c[i-1][j-1] || !c[i-1][j-1])
        &&     (cc == c[i][j-1] || !c[i][j-1])
        &&     (cc == c[i][j] || !c[i][j]);  
    };
    queue<pii> q;
    int count = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            if (i && j && check(i, j)) {
                q.push(pii(i,j));
            }
        }
    }
    vvi done(n, vi(m));
    vector<pii> arr;
    vi brr;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (check(x,y)) {
            int maxx = maxc(i, j);
            if (c[x][y]) count++;
            if (c[x][y-1]) count++;
            if (c[x-1][y-1]) count++;
            if (c[x-1][y]) count++;
            c[x][y] = 0;
            c[x-1][y]= 0;
            c[x][y-1] = 0;
            c[x-1][y-1]= 0;
            done[x][y] = 1;
            if (maxx) {
                arr.push_back(pii(x,y));
                brr.push_back(maxx);
                for (int i = -1; i <= 1; i++) {
                    for (int j = -1; j <= 1; j++) {
                        if (((x+i) >= 1) && ((y+j) >= 1) && ((x+i) < n) && ((y+j) < m) && (!done[x+i][y+j])) {
                            q.push(pii(x+i, y+j));
                        }
                    }   
                }
            }
        }
    }
    if (count < n*m) {
        cout << -1 << endl;
    } else {
        cout << arr.size() << endl;
        for (int i = arr.size()-1; i >= 0; i--) {
            cout << arr[i].first << " " << arr[i].second << " " << brr[i] << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
