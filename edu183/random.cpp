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
template <typename T>
struct MemoryPool {
	vector<T*> pointers;
	vector<T> memory;
	MemoryPool (size_t sz) {
		memory.resize(sz);
		pointers.resize(sz);
		for (int i = 0; i < sz; i++) {
			pointers[i] = &memory[i];
		}
	}

	T* allocate() {
		T* ret = pointers.back();
		pointers.pop_back();
		return ret;
	};

	void deallocate(T* item) {
		pointers.push_back(item);
	}
};

void solve() {
    MemoryPool M(64);

    int item = M.allocate();

    M.deallocate(item);
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
