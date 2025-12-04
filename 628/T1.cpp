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
    cin >> t;
    ofstream out("T1.out");

    vector<string> vs(7);
    vs[0] = "abbccdd";
    vs[1] = "aabecfd";
    vs[2] = "ghheeff";
    vs[3] = "gghhijj";
    vs[4] = "aaddiij";
    vs[5] = "bacdeff";
    vs[6] = "bbcceef";
    while (t--) {
		int n;
		cin >> n;
		if (n % 2 == 1 && n < 7) {
			out << "NO" << endl;
			continue;
		}
		out << "YES" << endl;
		vector<vector<char>> ans(n, vector<char>(n, '?'));
		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					char c = ((i + j) % 2 == 0) ? 'a' : 'b';
					for (int x = 0; x < 2; x++) {
						for (int y = 0; y < 2; y++) {
							ans[i * 2 + x][j * 2 + y] = c;
						}
					}
				}
			}
		} else {
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 7; j++) {
					ans[i][j] = vs[i][j];
				}
			}
			for (int i = 7; i < n; i+=2) {
				char c1 = ((i / 2) % 2 == 1) ? 'z' : 'x';
				char c2 = ((i / 2) % 2 == 1) ? 'y' : 'w';
				char c3 = ((i / 2) % 2 == 1) ? 's' : 't';
				char c4 = ((i / 2) % 2 == 1) ? 'q' : 'r';
				ans[i][0] = ans[i+1][0] = ans[i+1][1] = c1;
				ans[i][1] = ans[i][2] = ans[i+1][2] = c2;
				ans[0][i] = ans[0][i+1] = ans[1][i+1] = c1;
				ans[1][i] = ans[2][i] = ans[2][i+1] = c2;
				for (int j = 3; j < i; j += 2) {
					for (int x = 0; x < 2; x++) {
						for (int y = 0; y < 2; y++) {
							if (j % 4 == 3) {
								ans[i+x][j+y] = c3;
							} else {
								ans[i+x][j+y] = c4;
							}
							ans[j+x][i+y] = ans[i+x][j+y];
						}
					}
				}
				for (int x = 0; x < 2; x++) {
					for (int y = 0; y < 2; y++) {
						ans[i+x][i+y] = 'm';
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				out << ans[i][j];
			}
			out << endl;
		}
    }

    return 0;
}
