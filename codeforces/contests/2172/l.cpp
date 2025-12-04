#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 222222;
const ld pi = atan2(0, -1);

struct point {
	ll x, y;
	
	point operator-(point o) {
		return {x - o.x, y - o.y};
	}
} a[maxn], c[maxn];

inline ll dist(point p1, point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

inline ll dot(point p1, point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

inline ll cross(point p1, point p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

inline int sgn(ll x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int n, r, sz;

int main() {
	scanf("%d%d", &n, &r);
	
	for (int i = 0; i < n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
	
	if (n <= 2) {
	    printf("%.10Lf\n", pi * r * r / 2);
	    return 0;
	}
	
	for (int i = 1; i < n; i++)
		if (a[i].y < a[0].y || (a[i].y == a[0].y && a[i].x < a[0].x)) swap(a[0], a[i]);
		
	sort(a + 1, a + n, [&](point p1, point p2) {
		ll c = cross(p1 - a[0], p2 - a[0]);
		if (! c) return dist(p1, a[0]) < dist(p2, a[0]);
		return c > 0;
	});
	
	for (int i = 0; i < n; i++) {
		while (sz > 1 && cross(c[sz - 1] - c[sz - 2], a[i] - c[sz - 2]) <= 0) sz--;
		c[sz++] = a[i];
	}
	
	c[sz] = c[0];
	c[sz + 1] = c[1];
	
	ld ans = 0;
	
	for (int i = 0; i < sz; i++) {
	    ld d = min(sqrt(dist(c[i], {0, 0})), abs(cross(c[i], c[i + 1])) / sqrt(dist(c[i], c[i + 1])));
	    ld theta = 2 * acos(d / r);
	    ans = max(ans, theta * r * r / 2 - d * sqrt(1ll * r * r - d * d));
	    
	    if (sgn(cross(c[i + 2] - c[i], c[i + 1] - c[i])) != sgn(cross((point) {0, 0} - c[i], c[i + 1] - c[i]))) ans = pi * r * r / 2;
	}
	
	printf("%.10Lf\n", ans);
}