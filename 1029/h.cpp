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
template<typename T>
struct Fenw {
    int n;
    vector<T> fenw;
    
    Fenw(int n) : n(n), fenw(n, 0) {}

    void update(int i, T delta) {
        for (; i < n; i = i | (i + 1))
            fenw[i] += delta;
    }

    T query(int i) {
        T sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += fenw[i];
        return sum;
    }

    T range_query(int l, int r) {
    	l = max(l, 0);
    	r = min(r, n - 1);
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<vector<int>> vec(n+1);
    for (int i = 0; i < n; i++) {
    	vec[a[i]].push_back(i);
    }
    vector<set<pii>> vs1(n+1);
    vector<set<pii>> vs2(n+1);
    multiset<int, greater<>> ans1;
    multiset<int, greater<>> ans2;
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
    	int idx = 0; 
    	while (idx < vec[i].size()) {
	    	int l = (vec[i][idx] + 1) / 2 - 1;
	    	if (l < 0) {
	    		idx++;
	    		continue;
	    	}
    		int prev = l;
	    	int score = 0;
	    	while (idx + 1 < vec[i].size() && (vec[i][idx+1] + 1) / 2 - 1<= prev + 1) {
	    		if ((vec[i][idx+1] + 1) / 2 - 1 == prev) {
	    			score++;	
	    		}
	    		idx++;
	    		prev = (vec[i][idx] + 1) / 2 - 1;
	    	}
	    	int r = (vec[i][idx] + 1) / 2 - 1;
	    	vs2[i].insert({l, 0});
	    	vs2[i].insert({r, 1});
    		idx++;
    		ans2.insert(score);
    		maxx = max(maxx, score);
    	}

    	if (n % 2 == 1 && a[n-1] == i) {
    		vec[i].pop_back();
    	}

    	idx = 0;
    	while (idx < vec[i].size()) {
	    	int l = vec[i][idx] / 2;
    		int prev = l;
	    	int score = 0;
	    	while (idx + 1 < vec[i].size() && vec[i][idx+1] / 2 <= prev + 1) {
	    		if (vec[i][idx+1] / 2 == prev) {
	    			score++;
	    		}
	    		idx++;
	    		prev = vec[i][idx] / 2;
	    	}
	    	int r = vec[i][idx] / 2;
	    	vs1[i].insert({l, 0});
	    	vs1[i].insert({r, 1});
    		idx++;
    		ans1.insert(score);
    		maxx = max(maxx, score);
    	}
    }
    // if (n == 300000 && a[0] <= 5) {
    // 	cout << maxx << endl;
    // }
    Fenw<int> F1(n / 2);
    Fenw<int> F2(n / 2);
    for (int i = 0; i < n - 1; i++) {
    	if (a[i] == a[i+1]) {
    		if (i % 2) {
    			F2.update(i / 2, 1);
    		} else {
    			F1.update(i / 2, 1);
    		}
    	}
    }
    for (int i = 0; i < q; i++) {
    	int id, x;
    	cin >> id >> x;

    	id --;
		int y = a[id];
		int ix1;
		int ix2;
		int target1;
		int target2;
    	if (id % 2 == 1) {
    		ix1 = id / 2;
    		ix2 = id / 2;
    		target1 = (id) ? a[id - 1] : -1;
    		target2 = (id != n-1) ? a[id + 1] : 0;
    	} else {
    		ix1 = id / 2;
    		ix2 = (id + 1) / 2 - 1;
    		target2 = (id) ? a[id - 1] : -1;
    		target1 = (id != n-1) ? a[id + 1] : -1;
    	}

		
		int zz,z;
		set<pii>::iterator it;
		if (vs1[y].size()) {
			it = vs1[y].lower_bound({ix1, 1});
			zz = (it == vs1[y].end()) ? n + 2 : (*it).first;
			if (it != vs1[y].begin()) {
				--it;
				z = (*it).first;
			} else {
				z = -2;
			}
		} else {
			zz = n + 2;
			z = -2;
		}
		if (target1 == y) {
			int summ = F1.range_query(z, zz);
			F1.update(ix1, -1);
			ans1.erase(ans1.find(summ));
			ans1.insert(summ-1);
		} else if (target1 != -1) {
			if (zz != ix1 && z != ix1) {
				int zzl = ix1 + 1;
				int summz = F1.range_query(z, zz);

				ans1.erase(ans1.find(summz));
				int summ = F1.range_query(zzl, zz);
				ans1.insert(summ);
				int zr = ix1 - 1;
				int summ2 = F1.range_query(z, zr);
				ans1.insert(summ2);
			}
			if (zz == ix1 && z == ix1) {
				ans1.erase(ans1.find(0));
			}
			if (zz != ix1) {
				if (ix1 != n / 2 - 1) vs1[y].insert({ix1 + 1, 0});
			} else {
				vs1[y].erase({ix1, 1});
			}
			if (z != ix1) {
				if (ix1) vs1[y].insert({ix1 - 1, 1});
			} else {
				vs1[y].erase({ix1, 0});
			}
		} 

		if (vs1[x].size()) {
			it = vs1[x].lower_bound({ix1, 1});
			zz = (it == vs1[x].end()) ? n + 2 : (*it).first;
			if (it != vs1[x].begin()) {
				--it;
				z = (*it).first;
			} else {
				z = -2;
			}
		} else {
			zz = n + 2;
			z = -2;
		}
		if (target1 == x) {
			int summ = F1.range_query(z, zz);
			F1.update(ix1, 1);
			ans1.erase(ans1.find(summ));
			ans1.insert(summ+1);
		} else if (target1 != -1) {
			if (zz == ix1 + 1 && z == ix1 - 1) {
				++it;
				++it;
				int zzr = (*it).first;
				int summ = F1.range_query(zz, zzr);
				ans1.erase(ans1.find(summ));
				--it;
				--it; --it;
				int zl = (*it).first;
				int summ2 = F1.range_query(zl, z);
				ans1.erase(ans1.find(summ2));
				ans1.insert(summ + summ2);
			}
			if (zz != ix1 + 1 && z != ix1 - 1) {
				ans1.insert(0);
			}
			if (zz != ix1+1) {
				vs1[x].insert({ix1, 1});
			} else {
				vs1[x].erase({ix1+1, 0});
			}
			if (z != ix1-1) {
				vs1[x].insert({ix1, 0});
			} else {
				vs1[x].erase({ix1-1, 1});
			}
		}

		if (vs2[y].size()) {
			it = vs2[y].lower_bound({ix2, 1});
			zz = (it == vs2[y].end()) ? n + 2 : (*it).first;
			if (it != vs2[y].begin()) {
				--it;
				z = (*it).first;
			} else {
				z = -2;
			}
		} else {
			zz = n + 2;
			z = -2;
		}
		if (target2 == y) {
			int summ = F2.range_query(z, zz);
			F2.update(ix2, -1);
			ans2.erase(ans2.find(summ));
			ans2.insert(summ-1);
		} else if (target2 != -1) {
			if (zz != ix2 && z != ix2) {
				int zzl = ix2 + 1;
				int summ = F2.range_query(zzl, zz);
				ans2.insert(summ);
				int zr = ix2 - 1;
				int summ2 = F2.range_query(z, zr);
				ans2.insert(summ2);
				ans2.erase(ans2.find(summ + summ2));
			}
			if (zz == ix2 && z == ix2) {
				ans2.erase(ans2.find(0));
			}
			if (zz != ix2) {
				if (ix2 != n / 2 - 1) vs2[y].insert({ix2 + 1, 0});
			} else {
				vs2[y].erase({ix2, 1});
			}
			if (z != ix2) {
				if (ix2) vs2[y].insert({ix2 - 1, 1});
			} else {
				vs2[y].erase({ix2, 0});
			}
		} 

		if (vs2[x].size()) {
			it = vs2[x].lower_bound({ix2, 1});
			zz = (it == vs2[x].end()) ? n + 2 : (*it).first;
			if (it != vs2[x].begin()) {
				--it;
				z = (*it).first;
			} else {
				z = -2;
			}
		} else {
			zz = n + 2;
			z = -2;
		}
		if (target2 == x) {
			int summ = F2.range_query(z, zz);
			F2.update(ix2, 1);
			ans2.erase(ans2.find(summ));
			ans2.insert(summ+1);
		} else if (target2 != -1) {
			if (zz == ix2 + 1 && z == ix2 - 1) {
				++it;
				++it;
				int zzr = (*it).first;
				int summ = F2.range_query(zz, zzr);
				ans2.erase(ans2.find(summ));
				--it;
				--it; --it;
				int zl = (*it).first;
				int summ2 = F2.range_query(zl, z);
				ans2.erase(ans2.find(summ2));
				ans2.insert(summ + summ2);
			}
			if (zz != ix2 + 1 && z != ix2 - 1) {
				ans2.insert(0);
			}
			if (zz != ix2+1) {
				vs2[x].insert({ix2, 1});
			} else {
				vs2[x].erase({ix2+1, 0});
			}
			if (z != ix2-1) {
				vs2[x].insert({ix2, 0});
			} else {
				vs2[x].erase({ix2-1, 1});
			}
		}

    	a[id] = x;
    	auto it2 = ans1.begin();
    	int a1 = *it2;
    	it2 = ans2.begin();
    	int a2 = *it2;
    	cout << max(a1, a2) << " ";

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
