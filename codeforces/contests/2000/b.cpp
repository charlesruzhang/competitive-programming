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
const int maxn = 222222;

int tt = 1, n, a[maxn];

int main() {
    scanf("%d", &tt);

    while(tt--) {
        scanf("%d", &n);

		bool f[n+2];
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), f[i] = 0;
    	
    	f[n+1] = 0;
    	f[0] = 0;
        f[a[1]] = 1;

        bool ans = 1;

        for (int i = 2; i <= n; i++) {
            if (! f[a[i] - 1] && ! f[a[i] + 1]) ans = 0;
            f[a[i]] = 1;
        }

        yorn(ans);
    }
}