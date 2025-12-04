#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
ll ans = 0;
ll M = 0;
int solve() {
    ll n;
    cin >> n;
    auto start = std::chrono::high_resolution_clock::now();
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            cout << i;
            n /= i;
            if (n!= 1) {
                cout << " * ";
            }
        } else {
            i++;
        }
    }
    cout << n << endl;
    auto end = std::chrono::high_resolution_clock::now(); // End time
    std::chrono::duration<double> duration = end - start; // Compute duration

    std::cout << "Execution time: " << duration.count() << " seconds\n";
    return 0;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}
