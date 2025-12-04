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
int solve(int n, int k, vi& a) {
    vi cnt(2 * n + 1);
    for (int i = 0; i < n; i++) {
    	cnt[a[i]]++;
    }
    vi pref(2 * n + 1);
    vi v;
    for (int i = 1; i <= 2 * n; i++) {
    	pref[i] = pref[i-1] + cnt[i];
    	if (cnt[i] > k) {
    		v.push_back(i);
    	}
    }
    reverse(v.begin(), v.end());
    int prev = 2 * n + 1;
    stack<pii> ponds;
    ponds.push({2 * n + 1, INF});
    int ans = 0;
    int z = 2 * n;
    for (int i = 0; i < v.size(); i++) {
    	int res = 0;
    	int l = v[i];
    	int c = 0;
    	while (z >= l) {
    		if (!cnt[z]) {
    			z--;
    			c++;
    		} else {
    			ponds.push({z + 1, c});
    			if (z != l) ponds.push({z, -cnt[z]});
    			c = 0;
    			z--;
    		}
    	}
    	int tot = cnt[l];
    	//int tot = pref[prev - 1] - pref[l - 1];
    	tot -= k;
		while (ponds.size()) {
			auto [L, X] = ponds.top();
			ponds.pop();
			if (X < 0) {
				tot += - X - 1;
				continue;
			}
			if (X > tot) {
				ponds.push({L + tot, X - tot});
				//cout << "! "<< L + tot + 1 << " " << X - tot << endl;
			}
			if (X >= tot) {
				ponds.push({L + tot - 1, -k});
			}
			int loc = L + tot - 1;
			tot -= min(tot, X);
			if (tot == 0) {
				ans = max(ans, loc - l);
				break;
			}
		}
    	prev = l;
    }
    return ans;
}
int brute(int n, int k, vi& a) {
	vi cnt(3 * n + 1);
	for (int i = 0; i < n; i++) {
		cnt[a[i]] ++;
	}
	int ans = 0;
	while (1) {
		int flag = 0;
		vi cnt2(3 * n + 1);
		for (int i = 0; i <= 3 * n; i++) {
			if (cnt[i] > k) {
				cnt2[i+1] += cnt[i] - 1;
				cnt2[i] += 1;
				flag = 1;
			} else {
				cnt2[i] += cnt[i];
			}
		}
		swap(cnt, cnt2);
		if (!flag) {
			return ans;
		}
		ans++;
	}
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 100000;
    mt19937 rng(31415);
    int N = 5;
    while (t--) {
    	int n = N;
    	int k = 2;
    	vi a(n);
    	auto dis = uniform_int_distribution<int>(1, 2 * n);
    	for (int i = 0; i < n; i++) {
    		a[i] = dis(rng);
    	}
        int r1 = solve(n, k, a);
    	int r2 = brute(n, k, a);
    	if (r1 != r2) {
    		cout << n << " " << k << endl;
    		for (int i = 0; i < n; i++) {
    			cout << a[i] << " ";
    		}
    		cout << endl;
    		cout << r1 << " " << r2 << endl;
    		assert(false);
    	}
    }
    return 0;
}
