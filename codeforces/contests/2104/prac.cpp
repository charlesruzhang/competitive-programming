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
    ll x, y;
};
struct Line {
    Point l;
    Point r;
};

pair<bool, ld> intersect(Line a, Line target) {
    ll ay = a.r.y - a.l.y;
    ll ax = a.r.x - a.l.x;
    ll ty = target.r.y - target.l.y;
    ll tx = target.r.x - target.l.x;
    if (ay * tx == ax * ty) {
        return {false, 0};
    }
    ll X1 = a.r.x - a.l.x;
    ll a1X = a.r.y - a.l.y;
    ll b1X = a.r.x * a.l.y - a.l.x * a.r.y;

    ll X2 = target.r.x - target.l.x;
    ll a2X = target.r.y - target.l.y;
    ll b2X = target.r.x * target.l.y - target.l.x * target.r.y;

    __int128 Dx = (__int128) b1X * X2 - (__int128) b2X * X1; 
    __int128 D = (__int128) a2X * X1 - (__int128) a1X * X2;

    __int128 Dy = a1X * Dx + b1X * D;

    if (a.l.y == a.r.y) {
        if (Dx >= a.l.x * D && Dx >= a.r.x * D) {
            return {false, 0};
        }
        if (Dx <= a.l.x * D && Dx <= a.r.x * D) {
            return {false, 0};
        }
    } else {
        if (a.l.x == a.r.x) {
            Dy = a2X * Dx + b2X * D;
            if (Dy >= a.l.y * D * X2 && Dy >= a.r.y * D * X2) {
                return {false, 0};
            }
            if (Dy <= a.l.y * D * X2 && Dy <= a.r.y * D * X2) {
                return {false, 0};
            }
        } else {
            if (Dy >= a.l.y * D * X1 && Dy >= a.r.y * D * X1) {
                return {false, 0};
            }
            if (Dy <= a.l.y * D * X1 && Dy <= a.r.y * D * X1) {
                return {false, 0};
            }
        }
    }

    if (target.l.y == target.r.y) {
        __int128 fact = Dx - target.l.x * D;
        __int128 unit = target.r.x * D - target.l.x * D;
        return { true, (ld) fact / (ld) unit};
    } else {
        __int128 fact, unit;
        if (a.l.x == a.r.x) {
            fact = Dy - target.l.y * D * X2;
            unit = target.r.y * D * X2 - target.l.y * D * X2;
        } else {
            fact = Dy - target.l.y * D * X1;
            unit = target.r.y * D * X1 - target.l.y * D * X1;
        }
        return { true, (ld) fact / (ld) unit};
    }
}
pair<bool, ld> same(Point p, Point q, Point target) {
    ll x1 = target.x - p.x;
    ll y1 = target.y - p.y;
    ll x2 = q.x - p.x;
    ll y2 = q.y - p.y;
    if (y2 * x1 != x2 * y1) {
        return {false, 0};
    }
    if (q.y == p.y) {
        return { true, (ld) x1 / (ld) x2};
    } else {
        return { true, (ld) y1 / (ld) y2};
    }
}
ld dist(Point p, Point q) {
    ll yy = (q.y - p.y) * (q.y - p.y);
    ll xx = (q.x - p.x) * (q.x - p.x); 
    return sqrt(xx + yy);
}
void solve() {
    int n;
    cin >> n;
    vector<Line> lines(n);
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        if (i) {
            lines[i-1].l = points[i-1];
            lines[i-1].r = points[i];
        }
    }
    lines[n-1].l = points[n-1];
    lines[n-1].r = points[0];
    ld ans = 0;
    auto inside = [&](__int128 lx, __int128 ly, __int128 large) {
    int cnt = 0;
    for (auto &seg : lines) {
        __int128 x1 = seg.l.x, y1 = seg.l.y;
        __int128 x2 = seg.r.x, y2 = seg.r.y;
        __int128 dx = x2 - x1;
        __int128 dy = y2 - y1;
        __int128 cross_num = dx * (ly - y1*large)
                           - dy * (lx - x1*large);
        if (cross_num == 0) {
            __int128 minx = x1 < x2 ? x1 : x2;
            __int128 maxx = x1 > x2 ? x1 : x2;
            __int128 miny = y1 < y2 ? y1 : y2;
            __int128 maxy = y1 > y2 ? y1 : y2;
            if (lx >= minx*large && lx <= maxx*large
             && ly >= miny*large && ly <= maxy*large)
                return true;
        }
        bool above1 = (y1*large > ly);
        bool above2 = (y2*large > ly);
        if (above1 != above2) {
            __int128 num = (x1*large - lx)*dy
                         + (ly - y1*large)*dx;
            if (dy > 0) {
                if (num > 0) cnt++;
            } else {
                if (num < 0) cnt++;
            }
        }
    }
    return (cnt & 1) != 0;
};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Line target = {points[i], points[j]};
            ld left = -1e8;
            ld right = 1e8;
            ll maxx = max(abs(points[j].y - points[i].y) , abs(points[j].x - points[i].x));
            __int128 large = maxx * 1000000;
            ll lepsx = (points[j].x - points[i].x);
            ll lepsy = (points[j].y - points[i].y);
            if (!inside(large * points[i].x + lepsx, large * points[i].y + lepsy, large)) {
                continue;
            }
            if (!inside(large * points[j].x - lepsx, large * points[j].y - lepsy, large)) {
                continue;
            }
            if (!inside(large * points[i].x - lepsx, large * points[i].y - lepsy, large)) {
                left = 0;
            }
            if (!inside(large * points[j].x + lepsx, large * points[j].y + lepsy, large)) {
                right = 1;
            }
            for (int k = 0; k < n; k++) {
                if (k == (i + n - 1) % n || k == (j + n - 1) % n) continue;
                auto [boos, tmp] = same(points[i], points[j], lines[k].r);
                if (boos) {
                    if (!inside(large * lines[k].r.x + lepsx, large * lines[k].r.y + lepsy, large) ||
                        !inside(large * lines[k].r.x - lepsx, large * lines[k].r.y - lepsy, large)) { 
                        if (tmp <= 0) {
                            left = max(left, tmp);
                        } else if (tmp >= 0) {
                            right = min(right, tmp);
                        }
                    }
                    continue;
                }
                auto [boo2, tmp2] = intersect(lines[k], target);
                if (boo2) {
                    if (tmp2 <= 0) {
                        left = max(left, tmp2);
                    } else if (tmp2 >= 0) {
                        right = min(right, tmp2);
                    }
                }
            }
            ld distance = dist(points[i], points[j]);
            ans = max(ans, distance * (right - left));
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
