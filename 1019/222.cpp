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

 
void solve(int N, int M) {
    if(N < M) swap(N, M);
    vi vec = {0};
    for(int i = 0; i < M; i++) {
        vi nvec;
        for(int x : vec) {
            nvec.pb(x << 1);
            if(!(x & 1)) nvec.pb((x << 1) + 1);
        }
        swap(nvec, vec);
    }
    const int maxn = 6e4;
    sort(all(vec));
    int mask = (1 << M) - 1;
    vector<vvi> tr(M);
    for(int i = 0; i < M; i++) {
        tr[i].resize(maxn);
        set<int> s;
        for(int x : vec) {
            int nx = (x << 1) & mask;
            s.ins(nx);
            if(!(x >> (M - 1) & 1) && (i == 0 || !(x & 1))) {
                s.ins(nx | 1);
            }
        }
        vi nvec(all(s));
        assert(sz(nvec) < maxn);
        for(int j = 0; j < sz(vec); j++) {
            int x = vec[j];
            int nx = (x << 1) & mask;
            tr[i][j].pb(lb(all(nvec), nx) - nvec.begin());
            if(!(x >> (M - 1) & 1) && (i == 0 || !(x & 1))) {
                tr[i][j].pb(lb(all(nvec), nx | 1) - nvec.begin());
            }
        }
        swap(nvec, vec);
    }
    mint dp[maxn];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            mint ndp[maxn];
            memset(ndp, 0, sizeof(ndp));
            for(int k = 0; k < sz(tr[j]); k++) {
                for(int l : tr[j][k]) {
                    ndp[l] += dp[k];
                }
            }
            swap(ndp, dp);
        }
    }
    mint ans = 0;
    for(auto b : dp) ans += b;
    cout << N << " " << M << " " << ans << nl;
}
 
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T = 1;
    // cin >> T;
    for (int i = 17; i <= 22; i++) {
        for (int j = 17; i * j <= 500; j++) {
            solve(i, j);
        }
    }
    return 0;
}