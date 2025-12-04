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
void solve(int n, int m) {
    if (n * m % 5) {
    	cout << "no" << endl;
    	return;
    }
    int flag = 0;
    if (n % 5 == 0) {
    	flag = 1;
    	swap(n, m);
    }
    if (n == 1 && m > 5) {
    	cout << "no" << endl;
    	return;
    }
    if (n == 1 && flag == 0) {
    	cout << "yes" << endl;
    	cout << "IIIII" << endl;
    	return;
    }
    if (n == 1) {
    	cout << "yes" << endl;
    	cout << "I\nI\nI\nI\nI\n";
    	return;
    }
    if (n == 2 && m == 5) {
    	cout << "no" << endl;
    	return;
    }
    vector<vector<char>> ans(n, vector<char>(m, 'I'));
    vector<string> v1 = {"UUXUU", "UXXXU", "UUXUU"};
    vector<string> v2 = {"VVVZV", "VZZZV", "VZVVV"};
    vector<string> v3 = {"LLLLNNNPPP", "LIIIIINNPP"};
    vector<string> v4 = {"LLLLNNNYYYYNNPP", "LIIIIINNYNNNPPP"};
    int start = 0;
    if (n % 3 == 0) {
    	start = 0;
    } else if (n % 3 == 1) {
    	start = 4;
    	for (int j = 0; j < m / 5; j++) {
			vector<string>& tar = (j % 2 ? v1 : v2);
			for (int i = (j % 2); i < (j % 2 + 3); i++) {
				for (int l = j * 5; l < j * 5 + 5; l++) {
					ans[i][l] = tar[i - j % 2][l - 5 * j];
				}
			}
    	}
    } else {
    	start = 2;
    	if (m % 10 == 0) {
    		for (int j = 0; j < m / 10; j++) {
    			for (int i = 0; i < 2; i++) {
    				for (int l = 10 * j; l < 10 * j + 10; l++) {
    					ans[i][l] = v3[i][l - 10 * j];
    				}
    			}
    		}
    	} else {
    		if (m == 5) {
    			start = 1;
    		} else {
    			for (int i = 0; i < 2; i++) {
    				for (int j = 0; j < 15; j++) {
    					ans[i][j] = v4[i][j];
    				}
    			}
    			for (int j = 0; j < m / 10 - 1; j++) {
	    			for (int i = 0; i < 2; i++) {
	    				for (int l = 15 + 10 * j; l < 10 * j + 25; l++) {
	    					ans[i][l] = v3[i][l - 10 * j - 15];
	    				}
	    			}
	    		}
    		}
    	}
    }
    int cur = 0;
    for (int i = start; i + 2 < n; i+=3) {
    	cur ^= 1;
		for (int j = 0; j < m / 5; j++) {
			vector<string>& tar = ((j % 2) ^ cur ? v1 : v2);
			for (int k = i; k < i + 3; k++) {
				for (int l = j * 5; l < j * 5 + 5; l++) {
					ans[k][l] = tar[k - i][l - 5 * j];
				}
			}
		}
	}
	// cout << "yes" << endl;
	// if (flag) {
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++) {
	// 			cout << ans[j][i];
	// 		}
	// 		cout << endl;
	// 	}
	// } else {
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			cout << ans[i][j];
	// 		}
	// 		cout << endl;
	// 	}
	// }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--) {
    	for (int i = 5; i <= 100; i+=5) {
    		for (int j = 1; j <= 100; j++) {
    			int n = i; int m = j;
        		solve(n, m);
    		}
    	}
    }
    return 0;
}
