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
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            v.push_back(pii(i - l, l));
            l = i;
        }
    }
    v.push_back(pii(n-l, l));
    vi abcu;
    vi bacu;
    int acu = 0;
    int bcu = 0;
    for (int i = 0; i < v.size(); i++) {
        int ll = v[i].second;
        int le = v[i].first;
        if (le % 2 == 1) {
            if (s[ll] == 'B') {
                bcu++;
            } else {
                acu++;
            }
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

            int ta = max(ba - bac, 0);
            bac+=ta;
            abc+=bacu[i]-1-ta;
            acu++;
            bcu++;
        } else {
            bac+=bacu[i];
        }
    }
    int abcc = abc;
    abc = 0;

    for (int i = 0; i < abcu.size(); i++) {
        if (abc + abcu[i] > ab) {
            int ta = max(ab - abc, 0);
            abc+=ta;
            bac+=abcu[i]-1-ta;
            acu++;
            bcu++;
        } else {
            abc+=abcu[i];
        }
    }
    if (bac > ba) {
        int ex = bac-ba;
        acu += ex;
        bcu += ex;
    }
    if (abcc +abc > ab) {
        int ex = abcc+abc-ab;
        acu += ex;
        bcu += ex;
    }
    if (bcu > b || acu > a) {
        cout << "NO" << endl;
        return;
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
