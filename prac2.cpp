#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int, int>;
ll ans = 0;
ll M = 0;
void merge(vector<ll>& x, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<ll> L(n1), R(n2);

    // Copy data to temp vectors
    for (int i = 0; i < n1; i++) L[i] = x[left + i];
    for (int i = 0; i < n2; i++) R[i] = x[mid + 1 + i];



    int i = 0;int j = 0; int k = left;
    while (i < n1 && j < n2) {
        if (R[j]-L[i] < M) {
            ans+=n1-i;
            j++;
        } else {
            i++;
        }
    }
    // Merge the temp arrays back
    i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            x[k] = L[i];
            i++;
        } else {
            x[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        x[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        x[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void mergeSort(vector<ll>& x, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(x, left, mid);
        mergeSort(x, mid + 1, right);
        merge(x, left, mid, right);
    }
}
int solve() {
    int n;
    ll m;
    cin >> n >> m;
    M = m;
    vi a(n);
    vector<ll> x;
    x.push_back(0);
    ll pref = 0;
    for (int i = 0;i  < n; i++) {
        cin >> a[i];
        pref+=a[i];
        x.push_back(pref);
    }
    mergeSort(x, 0, x.size()-1);
    cout << ans << endl;
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
