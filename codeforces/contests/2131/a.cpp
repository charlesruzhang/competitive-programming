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
vi primes;
vi pvec;
vi mu,p;
vi mu2(1e6+1, -1);
const int maxN = 1e6+1;
void sieve() {
    primes.assign(maxN, 1);
    mu.assign(maxN, 1);
    primes[0] = primes[1] = 0;
    mu[1] = 1;
    for (int i = 2; i < maxN; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j < maxN; j+=i) {
                primes[j] = 0;
                if ((j / i) % i == 0) {
                    mu[j] = 0;
                }
                mu[j] *= -1;
            }
            mu[i] = -1;
        }
    }
    mu2[1] = 1;
    p.assign(maxN, 0);
    for (int i = 2; i < maxN; i++) {
        if (p[i]) continue;
        mu2[i] = -1;

        if ((ll) i * i < maxN) {
            mu2[i * i] = 0;
            p[i * i] = 1;
        }

        for (int j = i + 1; (ll) i * j < maxN; j++) {
            if (mu2[i*j] == 0 || j % i == 0) mu2[i *j] = 0;
            else mu2[i * j] = -mu2[j];
            p[i * j] = 1;
        }
    }
    
    for (int i = 2; i < maxN; i++) {
    	if (mu[i] != mu2[i]) {
    		cout << i << " " << mu[i] << " " << mu2[i] << endl;
    	}
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    auto find = [&](int f, int s) {
    	vi cnt(m+1);
    	int t2t = 0;
		for (int i = 0; i < n; i++) {
			if (i == f || i == s) continue;
	    	int x = a[i];
	    	vi vec;
	    	for (int j = 1; j * j <= x; j++) {
	    		if (x % j == 0) {
	    			vec.push_back(j);
	    			if (j * j != x) vec.push_back(x / j);
	    		}
	    	}
	    	ll tot = 0;
	    	for (int v: vec) {
	    		if (v == 1) continue;
	    		tot -= mu[v] * cnt[v];
	    		cnt[v] ++;
	    	}
	    	if (tot != t2t) {
	    		return i;
	    	}
	    	t2t++;
	    }
	    return -1;
    };
    int first = find(-1, -1);
    if (first == -1) {
    	cout << 0 << endl;
    	return;
    } else {
    	int second;
    	for (int i = 0; i < first; i++) {
    		if (gcd(a[i], a[first]) == 1) {
    			second = i;
    			break;
    		}
    	}
    	int s1 = 0, s2 = 0;
    	int third = find(first, second);
    	int four;
    	if (third != -1) {
    		for (int i = 0; i < third; i++) {
	    		if (i != first && i != second && gcd(a[i], a[third]) == 1) {
	    			four = i;
	    			break;
	    		}
	    	}
	    	cout << first +1<< " " << second +1 << " " <<  third +1<< " " << four +1 << endl;
    	
	    } else {
	    	int third = -1, four = -1;
	    	for (int i = 0; i < n; i++) {
	    		if (i != first && i != second) {
	    			if (gcd(a[first], a[i]) == 1) {
	    				if (third == -1) {
	    					third = i;
	    				} else {
	    					if (gcd(a[second], a[third]) == 1) {
	    						four = third;
	    						third = i;
	    					} else if (gcd(a[second], a[i]) == 1) {
	    						four = i;
	    						break;
	    					}
	    				}
	    			} else if (gcd(a[second], a[i]) == 1) {
	    				if (four == -1) {
	    					four = i;
	    				} else {
	    					if (gcd(a[first], a[four]) == 1) {
	    						third = four;
	    						four = i;
	    					}
	    				}
	    			}
	    		}
	    		if (third != -1 && four != -1) break;
	    	}
	    	if (third == -1 || four == -1) {
	    		cout << 0 << endl;
	    		return;
	    	}
	    	cout << first +1<< " " << third +1<< " " << second +1 << " " << four +1 << endl;
    	}
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
