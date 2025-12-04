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
int N = 1e6;
vvi facts(N+1);
void comp() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j+=i) {
			facts[j].push_back(i);
		}
	}
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    stack<int> st, st2, st3, st4,st5;
    vi SL(n),SR(n),BL(n),BR(n),SEL(n);
    for (int i = 0; i < n; i++) {
    	while (st.size() && a[st.top()] >= a[i]) {
    		st.pop();
    	}
    	SL[i] = (st.size() ? st.top() : -1);
    	st.push(i);
    }
    for (int i = 0; i < n; i++) {
    	while (st5.size() && a[st5.top()] > a[i]) {
    		st5.pop();
    	}
    	SEL[i] = (st5.size() ? st5.top() : -1);
    	st5.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
    	while (st2.size() && a[st2.top()] >= a[i]) {
    		st2.pop();
    	}
    	SR[i] = (st2.size() ? st2.top() : n);
    	st2.push(i);
    }
    for (int i = 0; i < n; i++) {
    	while (st3.size() && a[st3.top()] <= a[i]) {
    		st3.pop();
    	}
    	BL[i] = (st3.size() ? st3.top() : -1);
    	st3.push(i);
    }
    for (int i = n - 1; i >= 0; i--) {
    	while (st4.size() && a[st4.top()] < a[i]) {
    		st4.pop();
    	}
    	BR[i] = (st4.size() ? st4.top() : n);
    	st4.push(i);
    }
	ll ans = 0;
	vi prev(N+1, -1);
	for (int i = 0; i < n; i++) {
		int l = max(0, BL[i] + 1), r = min(n - 1, BR[i] - 1);
		int x = a[i], idx = i;
		for (int v : facts[x]) {
			int z = prev[v];
			if (z >= l && SR[z] > i) {
				int left = max(l, SL[z] + 1);
				int right = min(r, SR[z] - 1);
				ans += 1ll * (right - idx + 1) * (z - left + 1);
				//cout <<"!!" << idx <<" " << z << " " << left << " " << right << endl;
			}
		}
		prev[x] = i;
	}
	vi prev2(N+1, n);
	for (int i = n - 1; i >= 0; i--) {
		int l = max(0, BL[i] + 1), r = min(n - 1, BR[i] - 1);
		int x = a[i], idx = i;
		//cout << i << " " << x <<" " << l <<" " << r << endl;
		for (int v : facts[x]) {
			int z = prev2[v];
			if (z <= r && SL[z] < i) {
				int left = max(l, SEL[z] + 1);
				int right = min(r, SR[z] - 1);
				ans += 1ll * (right - z + 1) * (idx - left + 1);
				//cout <<"$!" << idx <<" " << z << " " << left << " " << right << endl;
			}
		}
		prev2[x] = i;
	}
	cout << ans + n << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
