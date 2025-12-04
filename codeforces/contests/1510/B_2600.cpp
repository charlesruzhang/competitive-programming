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
struct Point {
    long long x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

inline Point operator-(const Point& a, const Point& b) {
    return {a.x - b.x, a.y - b.y};
}

inline __int128 crossVec(const Point& a, const Point& b) {
    return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

// Cross product (O->A) x (O->B)
inline __int128 cross(const Point& O, const Point& A, const Point& B) {
    return crossVec({A.x - O.x, A.y - O.y}, {B.x - O.x, B.y - O.y});
}

// Orientation test: 0=collinear, 1=clockwise, 2=counterclockwise
int orientation(const Point& p, const Point& q, const Point& r) {
    __int128 val = cross(p, q, r);
    if (val == 0) return 0;
    return (val > 0) ? 2 : 1;
}

bool onSegment(const Point& p, const Point& q, const Point& r) {
    return q.x >= min(p.x, r.x) && q.x <= max(p.x, r.x) &&
           q.y >= min(p.y, r.y) && q.y <= max(p.y, r.y);
}

// Segment-segment intersection
bool segmentsIntersect(const Point& p1, const Point& q1,
                       const Point& p2, const Point& q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

// Ray-segment intersection using integer arithmetic
// Ray: O + t*(P - O),   t >= 0
// Segment: A + u*(B - A),   0 <= u <= 1
bool raySegmentIntersect(const Point& O, const Point& P,
                         const Point& A, const Point& B) {
    Point r = {P.x - O.x, P.y - O.y};
    Point s = {B.x - A.x, B.y - A.y};
    __int128 rxs = crossVec(r, s);
    Point diff = {A.x - O.x, A.y - O.y};
    __int128 diffxr = crossVec(diff, r);
    if (rxs == 0) {
        if (diffxr != 0) return false;
        auto dot = [&](const Point& u, const Point& v) {
            return (__int128)u.x * v.x + (__int128)u.y * v.y;
        };
        if (dot(A - O, r) >= 0) return true;
        if (dot(B - O, r) >= 0) return true;
        return false;
    }
    __int128 numerator_t = crossVec(diff, s);
    __int128 numerator_u = crossVec(diff, r);
    if (rxs > 0) {
        if (numerator_t < 0) return false;
        if (numerator_u < 0 || numerator_u > rxs) return false;
    } else {
        if (numerator_t > 0) return false;
        if (numerator_u > 0 || numerator_u < rxs) return false;
    }
    return true;
}

// =========================
// Monotone Chain Convex Hull
// =========================

vector<Point> convexHull(vector<Point>& pts) {
    int n = pts.size(), k = 0;
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());            
    vector<Point> H(2 * n);
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], pts[i]) <= 0) k--;
        H[k++] = pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && cross(H[k-2], H[k-1], pts[i]) <= 0) k--;
        H[k++] = pts[i];
    }
    H.resize(k - 1);
    return H;
}
void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    ld ans = 1e16;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max((ld) p / pts[i].x, (ld) q / pts[i].y));
    }
    //cout << ans << endl;
    auto hull = convexHull(pts);
    const ll fac = 1e9;
    Point target = {fac * p, fac * q};
    hull.push_back(hull[0]);
    Point origin = {0, 0};
    for (int i = 0; i < hull.size() - 1; i++) {
        bool res = raySegmentIntersect(origin, target, hull[i], hull[i+1]);
        if (res) {
            auto [x1, y1] = hull[i];
            auto [x2, y2] = hull[i+1];
            ll cro = x2 * y1 - x1 * y2;
            ld a = (q * x2 - p * y2) / (ld) cro;
            ld b = -(q * x1 - p * y1) / (ld) cro;
            //cout << a << " " << b << endl;
            if (a < 0 || b < 0) continue;
            ans = min(ans, a + b);
        }   
    }
    cout << setprecision(10) << ans << endl;
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
