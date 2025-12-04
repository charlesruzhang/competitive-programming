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

int n;
struct node {
    ll p, m;
} a[maxn];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &a[i].m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].p);

    int l = 1, r = n >> 1;
    sort(a + 1, a + n + 1, [](node a, node b) { return a.p + a.m > b.p + b.m; });
    for (int i = 1; i <= n; i++) {
    	cout << a[i].m << " ";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
    	cout << a[i].p << " ";
    }
    cout << endl;
    while (l <= r) {
        int mid = l + r >> 1;

        ll cost = 0;        
        priority_queue<pii, vector<pii>, greater<>> pq2, pq3;
        priority_queue<pii> pq1;

        for (int i = 1; i <= mid; i++) cost -= a[i].m, pq2.push({a[i].m + a[i].p, i});
        
        for (int i = mid + 1; i <= n; i++) {
            pq1.push({a[i].p, i});
            cost += a[i].p;

            if (pq1.size() > mid) {
                cost -= pq1.top().first;
                pq3.push({a[pq1.top().second].m, pq1.top().second});
                pq1.pop();
            }
        }

        while (1) {
            int tmp2 = pq2.top().second;
            pq2.pop();
            pq3.push({a[tmp2].m, tmp2});
            int tmp3 = pq3.top().second;
            pq3.pop();
            pq1.push({a[tmp3].p, tmp3});
            int tmp1 = pq1.top().second;
            pq1.pop();
            pq3.push({a[tmp1].m + a[tmp1].p, tmp1});
            ll C = a[tmp1].m + a[tmp1].p - a[tmp2].m - a[tmp3].p;
            cost -= C;
            cout << tmp1 << " " << tmp2 << " " << tmp3 << " " << C << endl;
            //cout << tmp1 << " " << a[tmp2].m << " " << a[tmp3].p << " " << a[tmp1].m + a[tmp1].p - a[tmp2].m - a[tmp3].p << endl;
            cout << mid << " !!!!" << endl;
            assert(C >= 0);
            if (C == 0) break;
        }

        if (cost <= 0) l = mid + 1;
        else r = mid - 1;
    }

    printf("%d\n", r);
}