#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../Templates/C++/debug.h"
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define lso(s) ((s) & -(s))
int lg(ll s) { return s ? __builtin_clzll(1) - __builtin_clzll(s) : -1; }//lg(1)=0, lg(2)=1, lg(3)=1, lg(4)=2, ...
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const char nl = '\n';
const int INF = 1e9;
const ll INFL = 4e18;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll floor(ll a, ll b) { return a / b - (a % b < 0); }
ll ceil(ll a, ll b) { return a / b + (a % b > 0); }

template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gen() {
	ll x = 0;
	while(x == 0)
		x = rng() % MOD;
	return x;
}

struct mint {
  ll x;
  mint(ll x=0):x((x%MOD+MOD)%MOD){}
  mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
  mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
  mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
  mint operator+(const mint a) const {mint res(*this);return res+=a;}
  mint operator-(const mint a) const {mint res(*this);return res-=a;}
  mint operator*(const mint a) const {mint res(*this);return res*=a;}
  mint pow(ll b) const {
    mint res(1), a(*this);
    while (b) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
    }
    return res;
  }
  // for prime MOD
  mint inv() const {return pow(MOD-2);}
  mint& operator/=(const mint a) {return (*this) *= a.inv();}
  mint operator/(const mint a) const {mint res(*this);return res/=a;}
};
ostream& operator<<(ostream& os, const mint& a) {os << a.x; return os;}

const int maxm = 1e6 + 5;
const int maxn = 20 + 5;
mint p[maxm][maxn];

void solve() {
    int N, M; cin >> N >> M;
    int K; cin >> K;
    vi v(K); cin >> v; for(auto &x : v) --x;
    if(M == 1) {
        cout << 1 << nl;
        return;
    }
    int dp[1 << N][N];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < N; i++) {
        for(int mask = 0; mask < (1 << (i + 1)); mask++) {
            if(i == 0) dp[mask][i] = mask + 1;
            else if((N - i) & 1) {
                int ma = 1;
                for(int x : v) {
                    if(x > i) break;
                    int nmask = (mask & ((1 << x) - 1)) | (mask >> (x + 1) << x);
                    ma = max(ma, dp[(mask & ((1 << x) - 1)) | (mask >> (x + 1) << x)][i - 1]);
                }
                dp[mask][i] = ma;
            } else {
                int mi = 2;
                for(int x : v) {
                    if(x > i) break;
                    mi = min(mi, dp[(mask & ((1 << x) - 1)) | (mask >> (x + 1) << x)][i - 1]);
                }
                dp[mask][i] = mi;
            }
        }
    }
    
    
    map<array<int, 4>, int> cnt;
    for(int mask = 0; mask < (1 << N); mask++) {
        if(dp[mask][N - 1] == 1) continue;
        for(int j = 0; j < N; j++) {
            if((mask >> j & 1) && dp[mask ^ (1 << j)][N - 1] == 1) {
                array<int, 4> ar = {0, 0, 0, 0};
                for(int i = 0; i < N; i++) {
                    if(j == i) continue;
                    if(mask >> i & 1) {
                        if(i < j) ar[0]++; //strictly greater
                        else ar[1]++; //greater or equal
                    } else {
                        if(i < j) ar[3]++; //less or equal
                        else ar[2]++; //strictly less
                    }
                }
                cnt[ar]++;
            }
        }
    }
    mint ans = 0;
    for(auto[ar, c] : cnt) {
        auto[w, x, y, z] = ar;
        for(int i = 1; i <= M; i++) {
            ans += mint(c) * i * p[M - i][w] * p[M - i + 1][x] * p[i - 1][y] * p[i][z];
        }
    }
    cout << ans << nl;
}


int main() {
    for(int i = 0; i < maxm; i++) {
        p[i][0] = 1;
    }
    for(int i = 0; i < maxm; i++) {
        for(int j = 1; j < maxn; j++) {
            p[i][j] = p[i][j - 1] * i;
        }
    }
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
	return 0;
}