#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define um unordered_map
#define us unordered_set
#define pb push_back
#define mp make_pair
#define yorn(f) puts(f? "yes" : "no")
#define newl printf("\n")

template<typename... Arg>
void print(string format, Arg... args) {
    #ifdef DEBUG 
    printf(format.c_str(), args...);
    #endif
}

const int mod = 998244353;
const int maxn = 111111;
const double eps = 1e-9;

int n, d[maxn], acc[maxn];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &d[i], &acc[i]);
    }

    double l = 0, r = 1e18;

    while (r - l >= 1e-6) {
        double v = (l + r) / 2;

        bool f = 1;
        for (int i = 1; i <= n; i++) {
            double a = 0.5 * acc[i], b = v, c = -d[i];
            double del = b * b - 4 * a * c;

            if (del < 0) {
                f = 0;
                break;
            }
            double t1 = (-b + sqrt(del)) / (2 * a), t2 = (-b - sqrt(del)) / (2 * a);
            if (t1 < 0 && t2 < 0) {
                f = 0;
                break;
            }
            if (t2 > 0 && t1 > t2) swap(t1, t2);
            v += acc[i] * t1;
        }

        if (f) r = (l + r) / 2;
        else l = (l + r) / 2;
    }

    double v = (l + r) / 2, tot = 0;

    printf("%.10lf ", v);

    for (int i = 1; i <= n; i++) {
        double a = 0.5 * acc[i], b = v, c = -d[i];
        double del = b * b - 4 * a * c;
        del = max(del, 0.0);
        double t1 = (-b + sqrt(del)) / (2 * a), t2 = (-b - sqrt(del)) / (2 * a);

        if (t2 > 0 && t1 > t2) swap(t1, t2);

        v += acc[i] * t1;
        tot += t1;
    }

    printf("%.10lf\n", tot);
}