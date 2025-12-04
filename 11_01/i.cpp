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
vi query (vi& a) {
	int sz = a.size();
	cout << "? " << sz << " ";
	for (int i = 0; i < sz; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	int tot;
	cin >> tot;
	vi ret(tot);
	for (int i = 0; i < tot; i++) {
		cin >> ret[i];
	}
	return ret;
}
void solve() {
    int n;
    cin >> n;
    vi s(1, 1);
    vi ret = query(s);
    int sz = ret.size();
    int k = sz;
    vi F;
    for (int i = 0; i < k; i++) {
    	F.push_back(ret[i]);
    }
    vvi ans(n);
    ans[0] = F;
    auto FUNC = [&] (int J, int K) {
    	//cout << J << " " << K << endl;
    	if (J > K) return;
	    vi t;
	    for (int i = 1; i < n; i += 2) {
	    	t.push_back(1);
	    	t.push_back((i + 1) / 2 + J);
	    	if ((i + 1) / 2 + J == K + 1) {
	    		break;
	    	}
	    }
	    vi L = query(t);
	    sz = L.size();
	    int j = 0;
	    vvi VL;
	    int prev = 0;
	    for (int i = 0; i < sz; i++) {
	    	if (L[i] == F[j]) {
	    		j++;
	    		if (j == k) {
	    			j = 0;
	    			int start = i - k + 1;
	    			vi A;
	    			for (int z = prev; z < start; z++) {
	    				A.push_back(L[z]);
	    			}
	    			VL.push_back(move(A));
	    			prev = i + 1;
	    		}
	    	} else {
	    		j = (L[i] == F[0] ? 1 : 0);
	    	}
	    }
    	vi A;
    	for (int z = prev; z < sz; z++) {
    		A.push_back(L[z]);
    	}
    	 VL.push_back(move(A));
	    reverse(t.begin(), t.end());
	    vi R = query(t);
	    assert(L.size() == R.size());
	    vvi VR;
	    prev = 0;
	    j = 0;
	    for (int i = 0; i < sz; i++) {
	    	if (R[i] == F[j]) {
	    		j++;
	    		if (j == k) {
	    			j = 0;
	    			int start = i - k + 1;
	    			vi A;
	    			for (int z = prev; z < start; z++) {
	    				A.push_back(R[z]);
	    			}
	    			VR.push_back(move(A));
	    			prev = i + 1;
	    		}
	    	} else {
	    		j = (R[i] == F[0] ? 1 : 0);
	    	}
	    }
    	vi B;
    	for (int z = prev; z < sz; z++) {
    		B.push_back(R[z]);
    	}
    	VR.push_back(move(B));
	    int SZ = VL.size();
	    assert(VL.size() == VR.size());
	    int cur = J;
	   // for (int i = 0; i < SZ; i++) {
	   // 	cout << VL[i].size() << " " << VR[i].size() << endl;
	   // }
	    for (int i = 1, nxt; i < SZ; i = nxt) {
	    	nxt = i + 1;
	    	int j = SZ - i - 1;
	    	//cout << "???" << cur << endl;
	    	if (VL[i] == VR[j] && VL[i].size()) {
	    		ans[cur] = VL[i];
	    		cur++;
	    	} else {
	    		if (i == SZ - 1 && VL[i].size() == 0) break;
	    		if (i == SZ - 1) assert(false);
	    		ans[cur] = VL[i];
	    		for (int f: F) {
	    			ans[cur].push_back(f);
	    		}
	    		for (int f: VL[i+1]) {
	    			ans[cur].push_back(f);
	    		}
	    		nxt = i + 2;
	    		cur++;
	    	}
	    }
	};
	FUNC(1, n / 3);
	FUNC(n / 3, 2 * n / 3);
	FUNC(2 * n / 3, n - 1);
	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << ans[i].size() << " ";
		for (int x : ans[i]) {
			cout << x << " ";
		}
	}
	cout << endl;
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
