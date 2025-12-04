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
struct LiChao {
    struct Line {
        ll m, b;
        ll eval(ll x) const { return m*x + b; }
    };
    struct Node {
        Line ln;
        Node *l, *r;
        Node(const Line &v): ln(v), l(nullptr), r(nullptr) {}
    };

    ll L, R;
    Node* root = nullptr;

    LiChao(ll lo, ll hi) : L(lo), R(hi) {} // The lower/upper limits on X.

    void addLine(ll m, ll b) {
        Line nw{m,b};
        addLine(nw, root, L, R);
    }

    ll query(ll x) const {
        return query(x, root, L, R);
    }

private:
    void addLine(Line nw, Node*& nd, ll l, ll r) {
        if (!nd) {
            nd = new Node(nw);
            return;
        }
        ll mid = (l + r) >> 1;

        bool leftBetter = nw.eval(l)  < nd->ln.eval(l);
        bool midBetter  = nw.eval(mid) < nd->ln.eval(mid);

        if (midBetter) {
            Line tmp = nd->ln;
            nd->ln   = nw;
            nw       = tmp;
        }
        if (l == r) return;

        if (leftBetter != midBetter)
            addLine(nw, nd->l, l, mid);
        else
            addLine(nw, nd->r, mid+1, r);
    }

    ll query(ll x, Node* nd, ll l, ll r) const {
        if (!nd) return MAXX;
        ll res = nd->ln.eval(x);
        if (l == r) return res;
        ll mid = (l + r) >> 1;
        if (x <= mid)
            return min(res, query(x, nd->l, l, mid));
        else
            return min(res, query(x, nd->r, mid+1, r));
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<ll> ans(n);
    LiChao C(1, n+1);
    vl pref(n+1);
    int idx = 0;
    stack<pii> st;
    st.push({0, -1});
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first > a[i]) {
            st.pop();
        }
        int z = st.top().second;
        pref[i+1] = pref[z + 1] + 1ll * (i - z) * (a[i] + 1) - 1;
        st.push({a[i], i});
        C.addLine(2 + a[i], - 2 - 2 * i - 1ll * i * a[i] + pref[i+1] - a[i]);
        ans[i] = C.query(i+1);
    }
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
