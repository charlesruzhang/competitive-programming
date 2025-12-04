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
    int m;
    cin >> m;
    int timer = 0;
    map<string, int> ma;
    vector<vector<array<int, 5>>> V;
    vector<tuple<int, int, int, int>> T(m);
    vector<string> dict;
    for (int i = 0; i < m; i++) {
    	string c, P, s;
    	int t; 
    	cin >> c >> P >> t >> s;
    	t++;
    	int idx = 0;
    	if (ma.find(c) == ma.end()) {
    		ma[c] = timer;
    		idx = timer++;
    		V.emplace_back(26);
    		dict.push_back(c);
    	} else {
    		idx = ma[c];
    	}
    	int p = P[0] - 'A';
    	auto &[x, y, z, w, rr] = V[idx][p];
    	int Z = 0;
    	if (s == "accepted") {
    		if (y == 0) {
    			y = t;
    		} else if (w == 0) {
    			w = t;
    		}
    		Z = 1;
    	} else {
    		if (y == 0) {
    			x += 20;
    		}
    		if (w == 0) {
    			z += 20;
    		}
    	}
    	T[i] = {idx, p, t, Z};
    }
    int n = ma.size();
    assert(V.size() == n);
    vector<array<int, 3>> score(n);
    int N = 0;
    for (int i = 0; i < n; i++) {
    	int cnt = 0, tot = 0;
    	for (int j = 0; j < 26; j++) {
    		auto& [x, y, z, w, rr] = V[i][j];
    		if (y) {
    			cnt++;
    			tot += y + x - 1;
    		}
    	}
    	score[i] = {cnt, -tot, i};
    	if (cnt) N++;
    }
    vi rank(n);
    vector<array<int, 3>> S = score;
    sort(score.begin(), score.end(), greater<>());
    pii prev = {-1, -1};

    int Bm = min((N - 1 + 9) / 10, 35);
    int B = min((N + 9) / 10, 35);
    int Bp = min((N + 1 + 9) / 10, 35);
    //cout << "Bm" << Bm << "B" << B<<"Bp" << Bp << endl;
    int j = -1;
    set<int> ans;
    vi L, R;
    pii tar = {-1, -1};
    int done = 1;

    pii tar2 = {-1, -1};
    int done2 = 1;

    pii mintar = {INF, INF};
    pii mintar2 = {INF, INF};
    for (int i = 0; i < n; i++) {
    	auto& [cnt, tot, idx] = score[i];
    	tot = -tot;
    	if (cnt != prev.first || tot != prev.second) {
    		j = i;
    	}
    	if (cnt) rank[idx] = j;
    	else rank[idx] = INF;
    	prev = {cnt, tot};
    	if (rank[idx] < B) {
    		ans.insert(idx);
    		if (cnt < mintar.first || (cnt == mintar.first && tot > mintar.second)) {
    			mintar = {cnt, tot};
    		}
    	}
    	if (rank[idx] == B) {
    		L.push_back(idx);
    		tar = {cnt, tot};
    		done = 0;
    	}
    	if (rank[idx] == Bm) {
    		R.push_back(idx);
    		tar2 = {cnt, tot};
    		done2 = 0;
    	}
    } 
    if (tar.first == -1) {
    	tar = mintar;
    }
    for (int i = 0; i < m; i++) {
    	auto& [idx, p, t, Z] = T[i];
    	int ncnt = S[idx][0];
    	int ntot = S[idx][1];
    	int flag = (ncnt == 0 ? 1 : 0);
    	ntot = -ntot;
    	if (rank[idx] < B) {
    		if (!Z) continue;
    		auto &[x, y, z, w, rr] = V[idx][p];
    		assert(y > 0);
    		if (t != y) continue;
    		if (w > 0) {
    			ntot += w + z + 20 - (x + y);
    		} else {
    			ntot -= x + y - 1;
    			ncnt --;
    		}
    		if (ncnt == 0) {
    			if (done2) continue;
    			assert(ntot == 0);
    			done2 = 1;
    			for (int r : R) {
    				ans.insert(r);
    			}
    			continue;
    		}
    		if (!done && (ncnt < tar.first || (ncnt == tar.first && ntot >= tar.second))) {
	    		done = 1;
	    		for (int l : L) {
	    			ans.insert(l);
	    		}
	    	}
    	} else {
    		auto &[x, y, z, w, rr] = V[idx][p];
    		if (Z) {
    			rr = -1;
    		}
    		if (y > 0) {
    			if (rr == -1) continue;
    			ntot -= x + y - t - rr;
    		} else {
    			ntot += rr + t - 1;
    			ncnt ++;
    		}
    		rr += 20;
    		if (flag && ncnt && Bp != B) {
    			//cout << "?" << tar.first << " " << tar.second << endl;
    			if (tar.first == INF || ncnt > tar.first || (ncnt == tar.first && ntot <= tar.second)) {
    				ans.insert(idx);
    			}
    			// cout << done << " " << ncnt << " " << ntot << endl;
    			// cout << tar.first << " " << tar.second << endl;
    			if (!done && (ncnt < tar.first || (ncnt == tar.first && ntot >= tar.second))) {
	    			done = 1;
	    			for (int l : L) {
	    				ans.insert(l);
	    			}
	    		}
    			continue;
    		}
    		if (ncnt > mintar.first || (ncnt == mintar.first && ntot <= mintar.second)) {
	    		ans.insert(idx);
	    	}
    	}
    	
    }
    cout << ans.size() << endl;
    for (int x : ans) {
    	cout << dict[x] << " ";
    }
    cout << endl;
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
