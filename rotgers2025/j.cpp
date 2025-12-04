// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
    pt operator*(long long d) const { return pt(x*d, y*d); }
    pt operator/(long long d) const { return pt(x/d, y/d); }
    long long cross(const pt &p) const { return x * p.y - y * p.x; }
    long long dot(const pt &p) const { return x * p.x + y * p.y; }
    long long cross(const pt &a, const pt &b) const { return (a - *this).cross(b - *this); }
    long long dot(const pt &a, const pt &b) const { return (a - *this).dot(b - *this); }
    long long sqrLen() const { return this->dot(*this); }
};

bool lexComp(const pt &l, const pt &r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

int sgn(long long val) { return val > 0 ? 1 : (val == 0 ? 0 : -1); }

vector<pt> seq;
pt translation;
int n;

bool pointInTriangle(pt a, pt b, pt c, pt point) {
    long long s1 = abs(a.cross(b, c));
    long long s2 = abs(point.cross(a, b)) + abs(point.cross(b, c)) + abs(point.cross(c, a));
    return s1 == s2;
}
bool same_half_plane(pt A, pt B, pt P1, pt P2) {
    long long cp1 = A.cross(B, P1);
    long long cp2 = A.cross(B, P2);

    return (cp1 >= 0 && cp2 >= 0) || (cp1 <= 0 && cp2 <= 0);
}
bool same_half_plane2(pt A, pt B, pt P1, pt P2) {
    long long cp1 = A.cross(B, P1);
    long long cp2 = A.cross(B, P2);

    return (cp1 > 0 && cp2 > 0) || (cp1 < 0 && cp2 < 0);
}
pair<int, pt> intersect(pt s1, pt e1, pt s2, pt e2) {
    auto d = (e1 - s1).cross(e2 - s2);
    if (d == 0) // if parallel
        return {0, pt(0, 0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    if ((s1 * p + e1 * q).x % d != 0 || (s1 * p + e1 * q).y % d != 0) {
    	return {0, pt{0, 0}};
    }
    return {1, (s1 * p + e1 * q) / d};
}
bool collinear(pt a, pt b, pt c) {
    return a.cross(b, c) == 0;
}
void solve() {
	vector<pt> a(3);
	vector<pt> b(3);
    for (int i = 0; i < 3; i++) {
    	int x, y;
    	cin >> x >> y;
    	a[i] = {x, y};
    }
    pt summ = a[0] + a[1] + a[2];
    for (int i = 0; i < 3; i++) {
    	b[i] = summ - a[i] - a[i];
    }
    vector<vector<pt>> c(3);
    for (int i = -200; i <= 300; i++) {
    	for (int j = -200; j <= 300; j++) {
    		pt p = {i, j};
    		int flag = 1;
    		for (int z = 0; z < 3; z++) {
    			if (p.x == a[z].x && p.y == a[z].y) {
    				flag = 0;
    				break;
    			}
    		}
    		if (!flag) continue;
    		if (pointInTriangle(a[0], a[1], a[2], p)) continue;
    		if (pointInTriangle(a[0], a[1] * 2 - a[0], a[2] * 2 - a[0], p)) {
    			c[0].push_back(p);
    		}
    		if (pointInTriangle(a[1], a[2] * 2 - a[1], a[0] * 2 - a[1], p)) {
    			c[1].push_back(p);
    		}
    		if (pointInTriangle(a[2], a[0] * 2 - a[2], a[1] * 2 - a[2], p)) {
    			c[2].push_back(p);
    		}
    	}
    }
    ll ans = 0;
    set<array<pll, 3>> S;
    vector<pll> A(3);
    A[0] = {a[0].x, a[0].y};
    A[1] = {a[1].x, a[1].y};
    A[2] = {a[2].x, a[2].y};
    for (int i = 0; i < 3; i++) {
    	for (pt p: c[i]) {
    		if (collinear(p, a[(i + 1) % 3], a[(i + 2) % 3])) continue;
    		pt q = a[(i + 1) % 3] - p;
    		pt r = a[(i + 2) % 3] - p;
    		int x1 = q.x;
    		int y1 = q.y;
    		int g = gcd(abs(x1), abs(y1));
    		x1 /= g;
    		y1 /= g;
    		pt start = a[(i + 1) % 3];
    		pt now = start;
    		pt delta = {x1, y1};
    		while (same_half_plane(b[(i + 1) % 3], a[i], start, now)) {
    			if (now.x == start.x && now.y == start.y) {
    				now = now + delta;
    				continue;
    			}
    			auto [b, res] = intersect(now, a[i], p, a[(i + 2) % 3]);
    			b &= (!same_half_plane2(a[i], a[(i + 2) % 3], res, a[(i + 1) % 3]));
    			if (b) {
    				array<pll, 3> PT;
    				PT[0] = {now.x, now.y};
    				PT[1] = {p.x, p.y};
    				PT[2] = {res.x, res.y};
    				int flag = 1;
    				for (int zz = 0; zz < 3; zz++) {
    					for (int yy = 0; yy < 3; yy++) {
    						if (PT[zz] == A[yy]) {
    							flag = 0;
    							break;
    						}
    					}
    					if (!flag) break;
    				}
    				if (flag) {
    					sort(PT.begin(), PT.end());
    					S.insert(PT);
    				}
    			}
    			now = now + delta;
    		}
    		int x2 = r.x;
    		int y2 = r.y;
    		int g2 = gcd(abs(x2), abs(y2));
    		x2 /= g2;
    		y2 /= g2;

    		start = a[(i + 2) % 3];
    		now = start;
    		delta = {x2, y2};
    		while (same_half_plane(b[(i + 2) % 3], a[i], start, now)) {
    			if (now.x == start.x && now.y == start.y) {
    				now = now + delta;
    				continue;
    			}
    			auto [b, res] = intersect(now, a[i], p, a[(i + 1) % 3]);
    			b &= (!same_half_plane2(a[i], a[(i + 1) % 3], res, a[(i + 2) % 3]));
    			if (b) {
    				array<pll, 3> PT;
    				PT[0] = {now.x, now.y};
    				PT[1] = {p.x, p.y};
    				PT[2] = {res.x, res.y};
    				int flag = 1;
    				for (int zz = 0; zz < 3; zz++) {
    					for (int yy = 0; yy < 3; yy++) {
    						if (PT[zz] == A[yy]) {
    							flag = 0;
    							break;
    						}
    					}
    					if (!flag) break;
    				}
    				if (flag) {
    					sort(PT.begin(), PT.end());
    					S.insert(PT);
    				}
    				
    			}
    			now = now + delta;
    		}
    	}
	}
	cout << S.size() << endl;
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
