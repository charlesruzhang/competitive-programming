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
    string s;
    cin >> s;
    int a,b,ab,ba;
    cin >> a >> b >> ab >> ba;
    int ca = 0;
    int cb = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            ca++;
        } else cb++;
    }
    if (a+b+ab*2+ba*2 < s.size()) {
        cout << "No" << endl;
        return;
    }
    if (a + ab + ba < ca || b + ab + ba < cb) {
        cout << "No" << endl;
        return;
    }
    int n = s.size();
    vector<pii> v;
    int l = 0;
    for (int i = 1; i < s.size(); i ++) {
        if (s[i] == s[i-1]) {
            v.push_back(pii(i - l, l));
            l = i;
        }
    }
    v.push_back(pii(n-l, l));
    sort(v.begin(), v.end(), greater<>());
    int tmp = 0;
    vi abcu;
    vi bacu;
    int acu = 0;
    int bcu = 0;
    for (int i = 0; i < v.size(); i++) {
        int ll = v[i].second;
        int le = v[i].first;
        if (le % 2 == 1) {
            int tr = (le - 1) / 2;
            if (s[ll] == 'B') {
                bcu++;
                if (bcu > b) {
                    cout << "No" << endl;
                    return;
                }
            } else {
                acu++;
                if (acu > a) {
                    cout << "NO" << endl;
                    return;
                }
            }
            tmp+=tr;
        } else {
            if (s[ll] == 'B') {
                bacu.push_back(le/2);
            } else {
                abcu.push_back(le/2);
            }
        }
    }
    sort(bacu.begin(), bacu.end());
    sort(abcu.begin(), abcu.end());
    int abc = 0;
    int bac = 0;
    for (int i = 0; i < bacu.size(); i++) {
        if (bac + bacu[i] > ba) {
            abc+=bacu[i]-1;
            acu++;
            bcu++;
            if (bcu > b || acu > a) {
                cout << "NO" << endl;
                return;
            }
        } else {
            bac+=bacu[i];
        }
    }
    if (abc > ab) {
        int ex = abc-ab;
        acu += ex;
        bcu += ex;
        if (bcu > b || acu > a) {
                cout << "NO" << endl;
                return;
        }
    }
    for (int i = 0; i < abcu.size(); i++) {
        if (abc + abcu[i] > ab) {
            bac+=abcu[i]-1;
            acu++;
            bcu++;
            if (bcu > b || acu > a) {
                cout << "NO" << endl;
                return;
            }
        } else {
            abc+=abcu[i];
        }
    }
    if (bac > ba) {
        int ex = bac-ba;
        acu += ex;
        bcu += ex;
        if (bcu > b || acu > a) {
                cout << "NO" << endl;
                return;
        }
    }
    cout << "YES" << endl;
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
