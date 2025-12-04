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
const ll MOD = 1e9+7;
const ll MAXX = 1e16;
int maxM = 1e4+5;

struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
vector<mi> fact(maxM);
vector<mi> ifact(maxM);
const int INF = 1e9 + 7;
void comp() {
    fact[0] = 1;
    for (int i = 1; i < maxM; i++) {
        fact[i] = fact[i-1] * i;
    }
    ifact[maxM-1] = inv(fact[maxM-1]);
    for (int i = maxM-2; i >= 0; i--) {
        ifact[i] = ifact[i+1] * (i + 1);
    }
}
void solve() {
    auto ncr = [&](int n, int k) {
        if(k < 0 || k > n) return mi(0);
        return fact[n] * ifact[k] * ifact[n-k];
    };
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pii> b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i].first >> b[i].second;
        b[i].first--;
    }
    vector<mi> ans(n);
    for (int i = 0; i < n; i++) {
        vi left;
        vi right;
        vi l, r;
        vi mid;
        for (int j = 0; j < q; j++) {
            if (b[j].first < i) {
                left.push_back(b[j].second + (i - b[j].first));
                l.push_back(b[j].second - (b[j].first - i));
            } else if (b[j].first > i) {
                right.push_back(b[j].second - (b[j].first - i));
                r.push_back(b[j].second - (b[j].first - i));
            } else {
                l.push_back(b[j].second);
                r.push_back(b[j].second);
                mid.push_back(b[j].second);
            }        
        }
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        sort(mid.begin(), mid.end());
        int k = 0, k2 = 0;
        int t = 0;
        if ((!left.size() || a[i] >= left[left.size()-1]) && (!right.size() || a[i] <= right[0]) && (!mid.size())) {
            ans[i] = a[i] * fact[q];
            continue;
        }
        mi cnt = 0;
        for (int j = 0; j < left.size(); j++) {
            if ((!r.size() || left[j] < r[0]) && !mid.size()) {
                if (j + 1 == left.size() && a[i] < left[j]) {
                    //assert(ans[i].v == 0);
                    ans[i] = fact[q] * left[j];
                    break;
                }
            }
            while (k < r.size() && left[j] >= r[k]) {
                k++;
            }
            while (k2 < right.size() && left[j] >= right[k2]) {
                k2++;
            }
            int sz = j + right.size() - k2;
            ans[i] += k * fact[q - 2 - sz] * ncr(q, sz) * fact[sz] * left[j]; 
        }

        k = 0; k2 = 0;
        for (int j = (int)right.size() - 1; j >= 0; j--) {
            if ((!l.size() || right[j] > l.back()) && !mid.size()) {
                if (j == 0 && a[i] > right[j]) {
                    assert(ans[i].v == 0);
                    ans[i] = fact[q] * right[j];
                    break;
                }
            }
            while (k < l.size() && right[j] <= l[l.size() - 1 - k]) {
                k++;
            }
            while (k2 < left.size() && right[j] <= left[left.size() - 1 - k2]) {
                k2++;
            }
            int sz = right.size() - 1 - j + left.size() - k2;
            ans[i] += k * fact[q - 2 - sz] * ncr(q, sz) * fact[sz] * right[j]; 
        }
        int x = 0;
        int y = 0;
        for (int j = 0; j < mid.size(); j++) {
            while (x < left.size() && left[x] < mid[j]) {
                x++;
            }
            while (y < right.size() && right[y] <= mid[j]) {
                y++;
            }
            int sz = x + (right.size() - y);
            ans[i] += mid[j] * fact[q-1-sz] * ncr(q, sz) * fact[sz];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (int) ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
