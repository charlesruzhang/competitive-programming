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
vector<int> sample_without_replacement(int N, int M, mt19937 &rng) {
    if (M > N) throw runtime_error("M must be <= N for distinct sampling");
    vector<int> a(N);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), rng);
    a.resize(M);
    return a;
}
void solve() {
    ofstream out("18.in");
    mt19937 rng(9);

    int N = 1e5;
    out << N << endl;
    for (int i = 1; i < N; i++) {
    	auto R = uniform_int_distribution<int>(1, i);
    	int t = i + 1;
    	out << R(rng) << " " << t << endl;
    }
    int Q = 10;
    out << Q << endl;
    for (int i = 0; i < Q; i++) {
    	int M = 100;
    	out << M << " ";
    	vi a = sample_without_replacement(N, M, rng);
    	for (int x : a) {
    		out << x << " ";
    	}
    	out << endl;
    }
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
