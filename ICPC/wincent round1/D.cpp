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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    ofstream out("D.out");
    ifstream in("D.txt");
    cin >> t;
    int X = 998244353;
    int Y = 1e9 + 7;
    while (t--) {
        vector<vvl> vec(10, vvl(15, vl(2)));
    	for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 15; j++) {
                string s;
                in >> s;
                int cnt = 0;
                vi v;
                for (int k = 1; k < s.size(); k++) {
                    if (s[k] == '#' && s[k-1] != '#') {
                        cnt = 1;
                    } else if (s[k] == '#') {
                        cnt ++;
                    } else if (s[k] == '.' && s[k-1] == '#') {
                        v.push_back(cnt);
                    }
                }
                vec[i][j][0] = v.size();
                //cout << i << " " << j << " " << v.size() << endl;
            }
        }
        int r, c;
        cin >> r >> c;
        vector<string> vs(r);
        vector<vector<ll>> vv(max(r, c), vl(2));
        for (int i = 0; i < r; i++) {
            cin >> vs[i];
            string s = vs[i];
            int cnt = 0;
            vi v;
            for (int k = 1; k < s.size(); k++) {
                if (s[k] == '#' && s[k-1] != '#') {
                    cnt = 1;
                } else if (s[k] == '#') {
                    cnt ++;
                } else if (s[k] == '.' && s[k-1] == '#') {
                    v.push_back(cnt);
                }
            }
            vv[i][0] = v.size();
        }

        int flag = 1;
        for (int i = 0; i < 10; i++) {
            int idx = 0;
            int j = 0;
            while (j < r) {
                if (idx < 15 && vec[i][idx][0] == vv[j][0]) {
                    idx++;
                }
                j++;
            }
            cout << idx << "??? " << endl;
            if (idx == 15) {
                out << i << endl;
                flag = 0;
                break;
            }
            idx = 14;
            j = 0;
            while (j < r) {
                if (idx >= 0 && vec[i][idx][0] == vv[j][0]) {
                    idx--;
                }
                j++;
            }
            cout << idx << "??. " << endl;
            if (idx == -1) {
                out << i << endl;
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < c; i++) {
            int cnt = 0;
            vi v;
            for (int k = 1; k < r; k++) {
                if (vs[k][i] == '#' && vs[k-1][i] != '#') {
                    cnt = 1;
                } else if (vs[k][i] == '#') {
                    cnt ++;
                } else if (vs[k][i] == '.' && vs[k-1][i] == '#') {
                    v.push_back(cnt);
                }
            }
            vv[i][0] = v.size();
        }
        for (int i = 0; i < 10; i++) {
            int idx = 0;
            int j = 0;

            while (j < c) {
                if (idx < 15 && vec[i][idx][0] == vv[j][0]) {
                    idx++;
                }
                j++;
            }
            cout << idx << "??, " << endl;
            if (flag && idx == 15) {
                out << i << endl;
                flag = 0;
                break;
            }
            idx = 14;
            j = 0;
            while (j < c) {
                if (idx >= 0 && vec[i][idx][0] == vv[j][0]) {
                    idx--;
                }
                j++;
            }
            cout << idx << "?,, " << endl;
            if (flag && idx == -1) {
                out << i << endl;
                flag = 0;
                break;
            }
        }
    }
    return 0;
}
