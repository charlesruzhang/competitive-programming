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
void solve() {
    vvi a(3, vi(10));
    string S = "ogrc";
    vector<pii> ans;
    auto rotate = [&] (int i, int x) {
    	if (x) ans.push_back({i, x});
    	vi now(10);
    	for (int j = 0; j < 10; j++) {
    		now[j] = a[i][(j + x) % 10];
    	}
    	swap(now, a[i]);
    };
    auto rc = [&] (int x) {
    	if (x) ans.push_back({3, x});
    	vvi A(3);
    	for (int i = 0; i < 3; i++) {
    		for (int j = 0; j < 3; j++) {
    			A[i].push_back(a[i][j]);
    		}
    	}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = A[(i + x) % 3][j];
			}
		}
    };
    for (int i = 0; i < 3; i++) {	
	    string s;
	    cin >> s;
	    for (int j = 0; j < 10; j++) {
	    	a[i][j] = s[j];
	    }
    }
    int z = 9;
    while (z >= 0 && a[1][z] == 'g') {
    	z--;
    }
    while (z >= 2) {
    	int flag = 1;
    	for (int i = 0; i < 3; i++) {
    		if (i == 1) continue;
    		for (int j = 0; j < 10; j++) {
    			if (a[i][j] == 'g') {
    				rotate(i, j);
    				rc((i + 2) % 3);
    				rotate(1, 1);
    				flag = 0;
    				break;
    			}
    		}
    		if (!flag) break;
    	}
    	if (!flag) {
    		z--;
    		continue;
    	}
    	assert(false);
    }
     // for (int i = 0; i < 3; i++) {
	// 		for (int j = 0; j < 10; j++) {
	// 			cout << (char)a[i][j];
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
    z = 9;
    while (z >= 0 && a[2][z] == 'r') {
    	z--;
    }
    while (z >= 2) {
    	int flag = 1;
    	for (int i = 0; i < 3; i++) {
    		if (i == 2) continue;
    		for (int j = 0; j < 10; j++) {
    			if (a[i][j] == 'r') {
    				if (i != 1) rotate(i, j), rc((i + 1) % 3);
    				else {
    					rc(1);
    					rotate(0, j);
    					rc(1);
    				}
    				rotate(2, 1);
    				flag = 0;
    				break;
    			}
    		}
    		if (!flag) break;
    	}
    	if (!flag) {
    		z--;
    		continue;
    	}
    	assert(false);
    }
    for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				cout << (char)a[i][j];
			}
			cout << endl;
		}
		cout << endl;
    // for (int i = 4; i < 10; i++) {
    // 	assert(a[1][i] == 'g');
    // }
    // for (int i = 4; i < 10; i++) {
    // 	assert(a[2][i] == 'r');
    // }
	int zz = 9;
	while (a[0][zz] == 'g') {
		zz--;
	}
    for (int y = 0; y < zz - 6; y++) {
    	int flag = 0;
    	if (!flag) {
	    	for (int i = 0; i < 3; i++) {
	    		for (int j = 0; j < 3; j++) {
	    			if (a[i][j] == 'g') {
	    				rc(i);
	    				rotate(0, j);
	    				rc(1);
	    				rotate(0, (10 - j) % 10);
	    				rc(2);
	    				rotate(0, 1);
	    				flag = 1;
	    				break;
	    			}
	    		}
	    		if (flag) break;
	    	}
	    }
	    if (!flag) {
		    for (int i = 0; i < 10; i++) {
		    	if (a[0][i] == 'g') {
		    		rotate(0, i);
		    		rc(1);
		    		rotate(0, (10 - i) % 10);
		    		rc(2);
		    		rotate(0, 1);
		    		flag = 1;
		    		break;
		    	}
		    }
		}for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				cout << (char)a[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
	

	rotate(0, 7);
	rc(1);
	zz = 9;
	while (a[0][zz] == 'r') {
		zz--;
	}
	// for (int i = 0; i < 3; i++) {
	// 		for (int j = 0; j < 10; j++) {
	// 			cout << (char)a[i][j];
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	for (int y = 0; y < zz - 6; y++) {
    	int flag = 0;
    	if (!flag) {
	    	for (int i = 0; i < 3; i++) {
	    		for (int j = 0; j < 3; j++) {
	    			if (a[i][j] == 'r') {
	    				rc(i);
	    				int zz = (i == 1 ? 2 : 1); 
	    				rotate(0, j);
	    				rc(zz);
	    				rotate(0, (10 - j) % 10);
	    				rc((3 - zz) % 3);
	    				rotate(0, 1);
	    				rc((3 - i) % 3);
	    				flag = 1;
	    				break;
	    			}
	    		}
	    		if (flag) break;
	    	}
	    }
	    if (!flag) {
		    for (int i = 0; i < 10; i++) {
		    	if (a[0][i] == 'r') {
		    		rotate(0, i);
		    		rc(1);
		    		rotate(0, (10 - i) % 10);
		    		rc(2);
		    		rotate(0, 1);
		    		flag = 1;
		    		break;
		    	}
		    }   
		}
		// for (int i = 0; i < 3; i++) {
		// 	for (int j = 0; j < 10; j++) {
		// 		cout << (char)a[i][j];
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
	}
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << (char)a[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	rotate(0, 7);
	rc(1);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++) {
			assert(a[i][j] == S[i]);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		auto [x, y] = ans[i];
		if (x <= 2) cout << S[x] << (10 - y) << endl;
		else cout << S[x] << y << endl;
	}
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
