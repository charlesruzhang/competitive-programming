#pragma optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<pii> movies(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        movies[i] = {x, y};
    }

    sort(movies.begin(), movies.end(), [](const pii &a, const pii &b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    });

    multiset<int> busy;
    for (int i = 0; i < k; i++) {
        busy.insert(0);
    }

    int ans = 0;
    for (pii m : movies) {
        auto it = busy.upper_bound(m.first);
        if (it == busy.begin())
            continue;
        it--;
        ans++;
        busy.erase(it);
        busy.insert(m.second);
    }
    cout << ans << endl;
}
