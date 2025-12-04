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
vi vec, vec2;
int N;
int target = 0;
int query(int op, int x) {
	char c = op + 'A';
	cout << c << " " << x << endl;
	int res = 0;
	// for (int i = x; i <= N; i+= x) {
	// 	res += vec[i];
	// }
	if (c == 'B') {
		for (int i = x; i <= N; i += x) {
			//if (i != target) vec[i] = 0;
			vec2[i] = 0;
		}
	}
	cin >> res;
	return res;
}
vi primes;
vi pvec;
const int maxN = 1e5+1;
void sieve() {
    primes.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    int limit = floor(sqrt(maxN));
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) {
            for (int j = i * i; j < maxN; j+=i) {
                primes[j] = 0;
            }
        }
    }
    pvec.clear();
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            pvec.push_back(i);
        }
    }
}
void solve() {
    int n;
    cin >> n;
    N = n;
    if (n == 1) {
    	cout << "C " << 1 << endl;
    	return;
    }
    //target = 78732;
    //vec.assign(n + 1, 1);
    vec2.assign(n + 1, 1);
    sieve();
    int cur = 1;
    int tot = 0;
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < pvec.size(); i++) {
    	if (pvec[i] * pvec[i] > n) {
    		idx = i;
    		break;
    	}
    }
    int i = pvec.size() - 1;
    while (pvec[i] > n) {
    	i--;
    }
    int j = 2;
    int B = 0;
    while (i >= idx && n >= 100) {
    	//cout << i << " " << cnt << endl;
    	int flag2 = 0;
    	while (pvec[i] * j > n) {
    		query(1, pvec[i]);
    		cnt++;
    		tot+= n / pvec[i];
    		i--;
    		flag2 = 1;
    	}
    	if (!flag2) {
    		j++;
    		continue;
    	}
    	int res = query(0, 1);
    	cnt++;
    	int flag = 0;
    	if (res != n - tot) {
    		for (int z = i + 1; pvec[z] * (j - 1) <= n; z++) {
    			int res = query(0, pvec[z]);
    			cnt++;
    			if (res) {
    				cur *= pvec[z];
    				flag = 1;
    				break;
    			}
    		}
    	}
    	if (!flag) {
    		j++;
    		continue;
    	}
    	for (int x = 0; x <= idx; x++) {
			ll z = 1;
			while (1) {
				if (z * pvec[x] <= n) z *= pvec[x];
				else break;
			}
			assert(z != 1);
			int res = query(1, z);
			cnt++;
			int flag2 = 1;
			while (z > pvec[x]) {
				z /= pvec[x];
				int res2 = 0;
				for (int x = z; x <= N; x += z) {
					res2+= vec2[x];
				}
				res = query(1, z);
	    		cnt++;
	    		//cout << z << " " << res << " " << res2 << endl;
				if (res != res2) {
					int fact = (B) ? pvec[x] : 1;
					cur *= z * fact;
					B = 0;
					flag2 = 0;
					break;
				}
			}
			if (!flag2) continue;
			assert(z == pvec[x]);
			res = query(0, pvec[x]);
			cnt++;
			int res2 = 0;
			for (int x = z; x <= N; x += z) {
				res2+= vec2[x];
			}
			if (res != res2) {
				cur *= z;
				B = 0;
			}
		}
    	cout << "C " << cur << endl;
    	return;
    } 
    cur = 1;
    B = 1;
	for (int i = idx; i >= 0; i--) {
		ll z = 1;
		while (1) {
			if (z * pvec[i] <= n) z *= pvec[i];
			else break;
		}
		assert(z != 1);
		int res = query(1, z);
		cnt++;
		int flag2 = 1;
		while (z > pvec[i]) {
			z /= pvec[i];
			int res2 = 0;
			for (int i = z; i <= N; i += z) {
				res2+= vec2[i];
			}
			res = query(1, z);
    		cnt++;
    		//cout << z << " " << res << " " << res2 << endl;
			if (res != res2) {
				int fact = (B) ? pvec[i] : 1;
				cur *= z * fact;
				B = 0;
				flag2 = 0;
				break;
			}
		}
		if (!flag2) continue;
		assert(z == pvec[i]);
		res = query(0, pvec[i]);
		cnt++;
		int res2 = 0;
		for (int i = z; i <= N; i += z) {
			res2+= vec2[i];
		}
		if (res != res2) {
			cur *= z;
			B = 0;
		}
	}
    cout << "C " << cur << endl; 
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
