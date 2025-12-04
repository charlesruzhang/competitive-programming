#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

#define yes ("yes")
#define no ("no")
#define printyes cout << yes << endl
#define printno cout << no << endl

#define ll long long
#define int ll

#define READ_VECTOR(name, size, type) \
    vector<type> name(size); \
    for(int i = 0; i < size; i++) { \
        cin >> name[i]; \
    }

#define READ_UGRAPH(name, size) \
    vector<vector<int>> name(size); \
    for(int i = 0; i < size; i++) { \
        int u, v; cin >> u >> v; \
        name[u-1].push_back(v-1); \
        name[v-1].push_back(u-1); \
    }

void solve() {
    int n; n = 631;
    int max_k = INT_MIN;

    vector<vector<int>> arrs(n);

    // good
    int summ = 0;
    for(int i = 0; i < n; i++) {
        int k; k = min(631ll, i);
        max_k = max(k, max_k);
        for(int j = 0; j < k; j++) {
            int ai; ai = 1;
            arrs[i].push_back(ai);
        }
        summ += k;
    }
    cout << summ << endl;
    // the index we are currently checking (good)
    int curr = 0;

    // this condition is correct, once curr == max_k that means
    // we have completely determined the output string
    ll tot = 0;
    while(curr < max_k) {
        int min_a = INT_MAX; // min value at curr
        int mi; // which array holds min value
        for(int i = 0; i < n; i++) {
            if (arrs[i].size() > curr && arrs[i][curr] < min_a) {
                min_a = arrs[i][curr];
                tot++;
                mi = i;
            } else if (arrs[i].size() > curr && arrs[i][curr] == min_a) {
                // compare arrs[i] and arrs[mi] lexicographically
                bool b = false;

                int s = min(arrs[i].size(), arrs[mi].size());
                tot++;
                for(int j = curr+1; j < s; j++) {
                    tot++;
                    if (arrs[i][j] < arrs[mi][j]) {
                        mi = i;
                        b = true;
                        break;
                    } else if (arrs[mi][j] < arrs[i][j]) {
                        b = true;
                        break;
                    }
                }

                if (!b) {
                    mi = (arrs[mi].size() < arrs[i].size()) ? mi : i;
                }
            }
        }
        for(int j = curr; j < arrs[mi].size(); j++) {
            //cout << arrs[mi][j] << ' ';
        }
        curr = arrs[mi].size();
    }

    cout << endl;
    cout << tot << endl;
}

signed main() {
    int t;
    //cin >> t;
    t = 1;
    for(int tp = 0; tp < t; tp++) {
        solve();
    }
}
