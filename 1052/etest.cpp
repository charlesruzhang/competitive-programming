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
        if (l > end || r < start) return T({1, n+1});//NEED TO INITIALIZE THIS!!!!!  
        if (l <= start && end <= r) return tree[node]; 
        int mid = (start + end) / 2;
        T left_result = query(l, r, 2 * node, start, mid);
        T right_result = query(l, r, 2 * node + 1, mid + 1, end);
        return combine(left_result, right_result);
    }
};
template<typename T>
struct Fenw {
    int n;
    vector<T> fenw;
    
    Fenw(int n) : n(n), fenw(n, 0) {}

    void update(int i, T delta) {
        for (; i < n; i = i | (i + 1))
            fenw[i] += delta;
    }

    T query(int i) {
        T sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += fenw[i];
        return sum;
    }

    T range_query(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
vi solve(int n, vi& a) {
    
    int mex = 0;
    int ans = 0;
    vi sol;
    for (int i = 0; i < n; i++) {
    	vi cnt(n+1);
        int ans = 0;
        for (int j = i; j >= 0; j--) {
            cnt[a[j]]++;
            int mex = n;
            int s = 0;
            for (int k = 0; k <= n; k++) {
                if (!cnt[k]) {
                    mex = k;
                } else if (k > mex) {
                    s+=cnt[k];
                }
            }
            ans = max(ans, s);
        }
        sol.push_back(ans);
    	//cout << ans << " ";
    }
    return sol;
}
vi solve2(int n, vi& a) {
    
    int mex = 0;
    int ans = 0;
    vi sol;
    for (int i = 0; i < n; i++) {
        if (a[i] != mex) {
            if (a[i] > mex) {
                ans++;
            }
        } else {
            ans = 0;
            using T = array<int, 2>;
            SegmentTree<T, function<T(T, T)>> seg(n+1, [&](T a, T b) { 
                auto [a1, a2] = a;
                auto [b1, b2] = b;
                if (a1 && b1) {
                    return T({1, n + 1});
                } else if (!a1) {
                    if (!b1 && b < a) {
                        return b;
                    } else {
                        return a;
                    }
                } else {
                    return b;
                }}, T({1, n+1}));
            Fenw<int> F(n+1);
            vector<T> arr(n+1);
            for (int i = 0; i <= n; i++) {
                arr[i] = {0, i};
            }
            seg.build(arr);

            for (int j = i; j >= 0; j--) {
                //if (j != i && a[j] == a[i]) break;
                seg.update(a[j], {1, a[j]});
                auto [x, y] = seg.query(0, n);
                F.update(a[j], 1);
                int z = F.range_query(y + 1, n);
                if (ans < z) {
                    ans = z;
                    mex = y;
                }
            }
        }
        sol.push_back(ans);
        //cout << ans << " ";
    }
    return sol;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 100000;
    //cin >> t;
    int N = 5;
    vi cnt(N);
    while (1) {
        mt19937 rng(31);
        auto X = uniform_int_distribution<int>(0, N);
        int n = N;
        vi a = cnt;
        int idx = N - 1;
        while (cnt[idx] == N && idx >= 0) {
            cnt[idx] = 0;
            idx--;
        }
        cnt[idx]++;
        vi sol = solve(n, a);
        vi sol2 = solve2(n, a);
        if (sol != sol2) {
            cout << n << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << sol[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < n; i++) {
                cout << sol2[i] << " ";
            }
            assert(false);
            break;
        } else {
            // cout << n << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << a[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << sol[i] << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << sol2[i] << " ";
            // }
            // cout << endl;
        }
        if (idx == -1) break;
    }
    return 0;
}
