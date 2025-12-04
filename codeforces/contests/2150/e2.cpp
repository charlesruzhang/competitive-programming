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
int query(vi& a, int x) {
	cout << "? " << x + 1 << " " << a.size() << " ";
	for (int y : a) {
		cout << y + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}
mt19937_64 RNG(31415929);
void solve() {
    int n;
    cin >> n;
    
    vi p(2 * n - 1);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), RNG);
    
    auto query_range = [&](int l, int r, int x){
        vector <int> s;
        for (int i = l; i <= r; i++){
            s.push_back(p[i]);
        }
        
        return query(s, x);
    };
    
    vi lf, rt, md;
    int l = 0;
    int r = 2 * n - 2;
    int mid = (l + r) / 2;
    for (int i = 0; i < n; i++){
        if (!query_range(l, mid, i)){
            rt.push_back(i);
        } else if (!query_range(mid + 1, r, i)){
            lf.push_back(i);
        } else {
            md.push_back(i);
        }
    }
    
    int left_size = lf.size() * 2 + md.size();
    int right_size = rt.size() * 2 + md.size();
    
    vi cand;
    
    if (left_size == mid - l + 1){
        l = mid + 1;
        cand = rt;
    } else {
        r = mid;
        cand = lf;
    }
    
    for (auto x : cand) {
        int lo = l, hi = r;
        while (lo != hi){
            int mid = (lo + hi) / 2;
            
            if (!query_range(lo, mid, x)){
                lo = mid + 1;
            } else if (!query_range(mid + 1, hi, x)){
                hi = mid;
            } else {
                break;
            }
        }
        if (lo == hi){
            cout << "! " << x + 1 << endl;
            return;
        }
    }
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
