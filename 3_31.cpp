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
    string s, t;
    cin >> s >> t;
    vector<string> x(3);
    vector<string> y(3);
    int i = 0;
    function <int(char, char)> match = [&](char c, char d) {
        int res = -1;
        if (c == 'l') {
            res = 0;
        } else if (c == 'h') {
            res = 3;
        } else if (c == 't') {
            res = 6;
        }
        if (d == 'a') {
            res += 0;
        } else if (d == 'o') {
            res += 2;
        } else if (d == 'e') {
            res ++;
        }
        return res;
    };
    vi arr;
    vi brr;
    while (i < s.size() - 1) {
        if (s[i] == 's') {
            i++;
        }
        int res = match(s[i], s[i+1]);
        arr.push_back(res);
        i++;
        if (s[i] == 'o') {
            i++;
        }
        i++;
    }
    i = 0;
    while (i < t.size() - 1) {
        if (t[i] == 's') {
            i++;
        }
        int res = match(t[i], t[i+1]);
        brr.push_back(res);
        i++;
        if (t[i] == 'o') {
            i++;
        }
        i++;
    }
    int A = 0;
    for (int i = 0; i < arr.size(); i++) {
        A = A * 9 + arr[i]; 
    }
    int B = 0;
    for (int i = 0; i < brr.size(); i++) {
        B = B * 9 + brr[i]; 
    }
    int C = A + B;
    vi crr;
    while (C > 0) {
        crr.push_back(C % 9);
        C /= 9;
    }
    reverse(crr.begin(), crr.end());
    string ans = "";
    for (int cc : crr) {
        if (cc >= 6) {
            ans += "t";
        } else if (cc >= 3) {
            ans += "sh";
        } else {
            ans += "l";
        }
        if (cc % 3 == 0) {
            ans += "a";
        } else if (cc % 3 == 1) {
            ans += "e";
        }  else {
            ans += "on";
        }
    }
    ans += "s";
    cout << ans << endl;
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
