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
 void solve() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
	 	cin >> a[i];
	}
	vi b;
	for (int i = 0; i < n - 1; i++) {
	 	if (a[i] != a[i+1]) {
	 		b.push_back(a[i]);
	 	}
	} 
	b.push_back(a[n-1]);
	int ans = 1;

	for (int i = 0; i < (int) b.size() - 1; i++) {
		if (b[i+1] % b[i] != 0) {
			b[i] /= ans;
			int g = b[i] / gcd(b[i], b[i+1]);
			b[i] /= g;
			ans *= g;
			if (b[i] > b[i+1]) {
				int g2 = b[i] / b[i+1];
				b[i] /= g2;
				ans *= g2;
			}
		}
	}
	cout << ans << endl;
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
 