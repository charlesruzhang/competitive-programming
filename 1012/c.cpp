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
using T = tuple<int, int, int>;
vector<T> pq;
vector<T> pq2;
void comp() {
    for (int i = 0; i < 400; i++) {
    	for (int j = 0; j < 400; j ++) {
    		pq.push_back({i* 3 + j * 3 + 2, 3 * i + 1, 3 * j + 1});
    		pq.push_back({i* 3 + j * 3 + 3, 3 * i + 1, 3 * j + 2});
    		pq.push_back({i* 3 + j * 3 + 3, 3 * i + 2, 3 * j + 1});
    		pq.push_back({i* 3 + j * 3 + 6, 3 * i + 2, 3 * j + 2});
    		pq2.push_back({i* 3 + j * 3 + 2, 3 * i + 1, 3 * j + 1});
    	}
    }
    sort(pq.begin(),pq.end());
    sort(pq2.begin(),pq2.end());
}
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    queue<pii> mark;
    int idx = 0;
    int idx2 = 0;
   	for (int i = 0; i < n; i++) {
   		if (a[i]) {
   			auto [x, y, z] = pq[idx];
   			int yy = -1;
   			int zz = -1;
   			if (!mark.empty()) {
   				yy = mark.front().first;
   				zz = mark.front().second;
   			}
   			while (yy == y && zz == z) {
   				idx++;
   				mark.pop();
   				auto [tt,uu, vv] = pq[idx];
   				y = uu;
   				z = vv;
   				if (mark.empty()) break;
   				yy = mark.front().first;
   				zz = mark.front().second;
   				//cout << "? " << y << " " << z << endl;
   			}
   			idx++;
   			cout << y << " " << z << endl;
   			auto [x2, y2, z2] = pq2[idx2];
   			if (y2 == y && z2 == z) {
   				idx2++;
   			}
   		} else {
   			auto [x, y, z] = pq2[idx2];
   			idx2++;
   			cout << y << " " << z << endl;
   			mark.push(pii(y,z));
   		}
   	}
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
