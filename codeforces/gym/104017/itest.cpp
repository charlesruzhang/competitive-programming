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
template<typename T, typename F>
struct SegmentTree {
    int n;
    vector<T> tree;
    F combine;  

    SegmentTree(int size, F comb, T default_value) : n(size), combine(comb) {
        tree.assign(4 * n, default_value);
    }

    void build(const vector<T> &arr, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int idx, T value, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(idx, value, 2 * node, start, mid);
            else
                update(idx, value, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T query(int l, int r, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (l > end || r < start) return INF;//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};


int solve(int n, int a, int b, vi& A) {
    a--; b--;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
    	c[i]= A[i];
    }
   using T = int;
    SegmentTree<T, function<T(T, T)>> seg1(n, [](T a, T b) {
        return  min(a, b); }, INF);
    SegmentTree<T, function<T(T, T)>> seg2(n, [](T a, T b) {
        return  min(a, b); }, INF);
    if (a > b) swap(a, b);
    vi dp(n, INF);
    dp[a] = 0;
    seg1.update(a, 0);
    seg2.update(a, 0);
    vvi L(n);
    vvi R(n);
    L[max(0, a - c[a])].push_back(a);
    R[min(n - 1, c[a] + a)].push_back(a);
    for (int z = 1; z <= a; z++) {
        if (a - z >= 0) {
            int i = a - z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            seg1.update(i, dp[i]);
            int l = max(0, i - c[i]);
            L[l].push_back(i);
            int r = min(n - 1, c[i] + i);
            if (r >= a + z) {
                R[r].push_back(i);
                seg2.update(i, dp[i]);
            }
            for (int x: L[i]) {
                seg1.update(x, INF);
            }
            L[i].clear();
        }

        if (a + z < n) {
            int i = a + z;
            dp[i] = min(dp[i], seg2.query(i - c[i], i - 1) + 1);
            seg2.update(i, dp[i]);
            int l = max(0, i - c[i]);
            if (l < a - z) {
                L[l].push_back(i);
                seg1.update(i, dp[i]);
            }
            int r = min(n - 1, c[i] + i);
            R[r].push_back(i);
            for (int x: R[i]) {
                seg2.update(x, INF);
            }
            R[i].clear();
        }
    }
    // for (int i = 0; i < n; i++) {
    //  cout << i << " " << dp[i] << endl;
    // }

    for (int i = 0; i < n; i++) {
        dp[i] = min(dp[i], seg2.query(i - c[i], i - 1) + 1);
        seg2.update(i, dp[i]);
        int r = min(n - 1, c[i] + i);
        R[r].push_back(i);
        for (int x: R[i]) {
            seg2.update(x, INF);
        }
        R[i].clear();
    }
    // for (int i = 0; i < n; i++) {
    //  cout << i << " " << dp[i] << endl;
    // }
     for (int z = n - 1 - b; z >= 0; z--) {
        if (b + z < n) {
            int i = b + z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            dp[i] = min(dp[i], seg2.query(i + 1, i + c[i]) + 1);
            seg1.update(i, dp[i]);
            int l = max(0, i - c[i]);
            L[l].push_back(i);
            int r = min(n - 1, c[i] + i);
            if (r >= a + z) {
                R[r].push_back(i);
                seg2.update(i, dp[i]);
            }
            for (int x: L[i]) {
                seg1.update(x, INF);
            }
            L[i].clear();
        }
 
        if (b >= z && z != 0) {
            int i = b - z;
            dp[i] = min(dp[i], seg1.query(i + 1, i + c[i]) + 1);
            dp[i] = min(dp[i], seg2.query(i + 1, i + c[i]) + 1);
            seg2.update(i, dp[i]);
            int l = max(0, i - c[i]);
            if (l < a - z) {
                L[l].push_back(i);
                seg1.update(i, dp[i]);
            }
            int r = min(n - 1, c[i] + i);
            R[r].push_back(i);
            for (int x: R[i]) {
                seg2.update(x, INF);
            }
            R[i].clear();
        }
    }
    return dp[b];
}
int brute(int n, int a, int b, vi& A) {
    a--; b--;
    vvi e(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (min(A[i], A[j]) >= abs(j - i)) {
                e[i].push_back(j);
                e[j].push_back(i);
            }
        }
    }
    queue<pii> q;
    q.push({0, a});
    vi vis(n);
    vi D(n, 1e9);
    vis[a] = 1;
    D[a] = 0;

    while (!q.empty()) {
        auto [d, u] = q.front();
        //cout << d << " " << u << endl;
        q.pop();
 
        for (int v : e[u]) {
            if (!vis[v]) {
                q.push({d + 1, v});
                D[v] = d + 1;
                vis[v] = 1;
            }
        } 
    }
    assert(D[b] < 1e9);
    return D[b];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 100000;
    mt19937 rng(31415);
    int N = 17;
    auto R = uniform_int_distribution<int>(1, N);
    //cin >> t;
    while (t--) {
        int n = N;
        int a = R(rng);
        int b = R(rng);
        vi A(n);
        for (int i = 0; i < n; i++) {
            auto R2 = uniform_int_distribution<int>(1, 10);
            A[i] = R2(rng);
        }
        int ans = solve(n, a, b, A);
        int ans2 = brute(n, a, b, A);
        if (ans != ans2) {
            cout << n << " " << a << " " << b << endl;
            for (int x : A) {
                cout << x << " ";
            }
            cout << endl;
            cout << ans << " " << ans2 << endl;
            assert(false);
        }
    }
    return 0;
}
