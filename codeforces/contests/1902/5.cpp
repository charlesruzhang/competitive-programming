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
struct Node {
	Node() {
		count = 0;
		for (int i = 0; i < 26; i++) {
			children[i] = nullptr;
		}
	}
	Node *children[26];
	int count;
};
void solve() {
    int n; 
    cin >> n;
    vector<string> a(n);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	tot += a[i].size();
    }
    Node *root = new Node();
    for (int i = 0; i < n; i++) {
    	Node* current = root;
    	for (int j = 0; j < a[i].size(); j++) {
    		int c = a[i][j] - 'a';
    		if (current->children[c] == nullptr) {
    			current->children[c] = new Node();
    		}
    		current = current ->children[c];
    		current->count++;
    	}
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	Node * current = root;
    	for (int j = a[i].size()-1; j >= 0; j--) {
    		int c = a[i][j] - 'a';
    		if (current->children[c] == nullptr) {
    			break;
    		}
    		current = current -> children[c];
    		ans += 2ll * current -> count;
    	}
    }
    cout << (tot * 2 * n) - ans << endl;
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
